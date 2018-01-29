/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/29 15:15:17 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	add_top_Z(t_fdf *fdf, double n)
{
	size_t	j;
	size_t	i;

	j = 0;
	ft_putendl("add_top_Z");
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
		{
			if (fdf->pnts.arr[j][i][ISTOP])
				fdf->pnts.arr[j][i][Z] += n;
			i++;
		}
		j++;
	}
}

void	change_projection(void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (fdf->pxls.pr_type == ORTOGONAL)
	{
		transform_pnts(fdf, -(IMG_WIDTH/2.0), -(IMG_HEIGHT/2.0), 0);
		fdf->pxls.pr_type = PERSPECTIVE;
	}
	else
	{
		transform_pnts(fdf, IMG_WIDTH/2.0, IMG_HEIGHT/2.0, 0);
		fdf->pxls.pr_type = ORTOGONAL;
	}
	return ;
}

int 	exit_key(int keycode, void *param)
{
	t_fdf 	*fdf;
	fdf = (t_fdf *)param;
	int		i;

	i = 0;
	static t_func_key_hook	func[21] = {
		{BUT_8,     mov_x_dec},
		{BUT_4,     mov_y_dec},
		{BUT_6,     mov_y_inc},
		{BUT_2,     mov_x_inc},
		{BUT_MIN,   mov_z_dec},
		{BUT_PLU,   mov_z_inc},
		{BUT_MUL,   scale_inc},
		{BUT_DIV ,  scale_dec},
		{BUT_SPACE, change_projection},
		{BUT_UP,    rotate_x_inc}, {BUT_DOWN,  rotate_x_dec},
		{BUT_LEFT,  rotate_y_inc}, {BUT_RIGHT, rotate_y_dec},
		{BUT_UPLF,  rotate_z_inc}, {BUT_DWRI,  rotate_z_dec},
		{BUT_A, sub_red}, {BUT_S, sub_grn}, {BUT_D, sub_blu},
		{BUT_Q, add_red}, {BUT_W, add_grn}, {BUT_E, add_blu}
		};
	while (i < 20)
	{	
		if(func[i].key == keycode)
		{
			func[i].f(param);
			break;
		}
		i++;
	}


	printf("exit givno, %d\n", keycode);
	if (keycode == BUT_ESC)
		exit(1);
	else if (keycode == BUT_8)
		mov_y(param, -fdf->mov_coeff);
	else if (keycode == BUT_2)
		mov_y(param, fdf->mov_coeff);
	else if (keycode == BUT_6)
		mov_x(param, fdf->mov_coeff);
	else if (keycode == BUT_4)
		mov_x(param, -fdf->mov_coeff);
	else if (keycode == BUT_MIN)
		mov_z(param, fdf->mov_coeff);
	else if (keycode == BUT_PLU)
		mov_z(param, -fdf->mov_coeff);	
	else if (keycode == BUT_MUL)
		scale_pnts(param, 2, 2, 2);
	else if (keycode == BUT_DIV)
		scale_pnts(param, 1/2.0, 1/2.0, 1/2.0);
	else if (keycode == BUT_UP)
		rotate_x_inc(param);
	else if (keycode == BUT_DOWN)
		rotate_x_dec(param);
	else if (keycode == BUT_LEFT)
		rotate_y_inc(param);
	else if (keycode == BUT_RIGHT)
		rotate_y_dec(param);
	else if (keycode == BUT_UPLF)
		rotate_z_inc(param);
	else if (keycode == BUT_DWRI)
		rotate_z_dec(param);
	else if (keycode == BUT_SPACE)
		change_projection(param);
	else if (keycode == BUT_BIGG)
		add_top_Z(param, 2);
	else if (keycode == BUT_LESS)
		add_top_Z(param, -2);
	else if (keycode == BUT_Q)
		add_red(param);
	else if (keycode == BUT_W)
		add_grn(param);
	else if (keycode == BUT_E)
		add_blu(param);
	else if (keycode == BUT_A)
		sub_red(param);
	else if (keycode == BUT_S)
		sub_grn(param);
	else if (keycode == BUT_D)
		sub_blu(param);
//	else if (keycode == BUT_C)
//		colorize(param);
//		jjjjjj

	get_pixel_arr(&fdf->pnts, &fdf->pxls);
	print_fdf(fdf->mlx, fdf->win, fdf->img, &fdf->pxls);
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
	fdf->pxls.pr_type = 0;
	get_point_arr(fdf->fd, &(fdf->pnts));
	transform_pnts(fdf, -fdf->pnts.center[X], -fdf->pnts.center[Y], 0);
	transform_pnts(fdf, IMG_WIDTH/2.0, IMG_HEIGHT/2.0, 0);
	init_pixel_arr(fdf);
	printf("POINT   col: %zu\trow: %zu\n", fdf->pnts.col,fdf->pnts.row);
	fdf->mov_coeff = 5;
 	fdf->rot_coeff = M_PI/180 * 4;
	init_rot_mat(fdf);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf	fdf;
		if ((fdf.fd = open(argv[1], O_RDONLY)) <= 0)
			return (-1);
		if (!(fdf.mlx = mlx_init()))
			return (-1);
		if (!(fdf.win = mlx_new_window(fdf.mlx,
						IMG_WIDTH, IMG_HEIGHT, "mlx 42")))
			return (-1);
		init_fdf(&fdf);
		print_fdf(fdf.mlx, fdf.win, fdf.img, &fdf.pxls);
        mlx_hook(fdf.win, 2, 5, exit_key, &fdf);
		mlx_loop(fdf.mlx);
	}
	ft_putendl_fd("usage: fdf source file", 2);
	return(0);
}
