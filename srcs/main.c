/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/19 15:26:09 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	change_projection(void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	fdf->pr_type++;
}

int 	exit_key(int keycode, void *param)
{
	t_fdf 	*fdf;
	fdf = (t_fdf *)param;

	printf("exit givno, %d\n", keycode);
	if (keycode == 53)
		exit(1);
	else if (keycode == BUT_8)
		mov_Y(param, -fdf->mov_coeff);
	else if (keycode == BUT_2)
		mov_Y(param, fdf->mov_coeff);
	else if (keycode == BUT_6)
		mov_X(param, fdf->mov_coeff);
	else if (keycode == BUT_4)
		mov_X(param, -fdf->mov_coeff);
	else if (keycode == BUT_MIN)
		mov_Z(param, fdf->mov_coeff);
	else if (keycode == BUT_PLU)
		mov_Z(param, -fdf->mov_coeff);	
	else if (keycode == BUT_MUL)
		scale_pnts(param, 2, 2, 2);
	else if (keycode == BUT_DIV)
		scale_pnts(param, 1/2.0, 1/2.0, 1/2.0);
	else if (keycode == BUT_UP)
		rotate_X(param, -fdf->rot_coeff);	
	else if (keycode == BUT_DOWN)
		rotate_X(param, fdf->rot_coeff);	
	else if (keycode == BUT_LEFT)
		rotate_Y(param, fdf->rot_coeff);	
	else if (keycode == BUT_RIGHT)
		rotate_Y(param, -fdf->rot_coeff);	
	else if (keycode == BUT_UPLF)
		rotate_Z(param, -fdf->rot_coeff);
	else if (keycode == BUT_DWRI)
		rotate_Z(param, fdf->rot_coeff);
//	else if (keycode == BUT_C)
//		coloroze(fdf);
	
	print_fdf(fdf->mlx, fdf->win, fdf->img, get_pixel_arr(fdf));
	return(0);
}

void	init_fdf_img(t_img *img, void *mlx_ptr)
{
	img->pnt_img = mlx_new_image(mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img->arr =
		mlx_get_data_addr(img->pnt_img, &img->bi_pp,
				&img->size_line, &img->endian);
	img->by_pp = img->bi_pp/8;
	printf("bi_pp: %d, size_line: %d, endian: %d\n", img->bi_pp, img->size_line,
			img->endian);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->img = malloc(sizeof(t_img));
	init_fdf_img(fdf->img, fdf->mlx);
	fdf->pr_type = 0;
	get_point_arr(fdf->fd, &(fdf->pnts));
	fdf->pxls = *get_pixel_arr(fdf);
	printf("POINT   col: %zu\trow: %zu\n", fdf->pnts->col,fdf->pnts->row);
	fdf->mov_coeff = 3;
	fdf->rot_coeff = M_PI/180 * 4;
	init_rot_mat(fdf);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf	fdf;
		if ((fdf->fd = open(argv[1], O_RDONLY)) <= 0)
			return (-1);
		if (!(fdf->mlx = mlx_init()))
			return (-1);
		if (!(fdf->win = mlx_new_window(fdf->mlx,
						IMG_WIDTH, IMG_HEIGHT, "mlx 42")))
			return (-1);
		
		init_fdf(&fdf);
		transform_pnts(&fdf, -fdf.pnts.center[X], -fdf.pnts.center[Y], 0);
		transform_pnts(*fdf, IMG_WIDTH/2.0, IMG_HEIGHT/2.0, 0);

		print_fdf(fdf.mlx, fdf.win, fdf.img, &fdf.pxls);
        mlx_hook(fdf.win, 2, 5, exit_key, &fdf);
		mlx_loop(fdf.mlx);
	}
	ft_putendl_fd("usage: fdf source file", 2);
	return(0);
}
