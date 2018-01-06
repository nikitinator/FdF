/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/06 17:36:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	normalize_pnts(t_pntarr *pnts)
{
	size_t	j;
	size_t	i;
	double	mag;

	j = 0;
	ft_putendl("normalize vec");	
	mag = sqrt(pow(pnts->center[X], 2) + pow(pnts->center[X], 2)
				   	+ pow(pnts->center[X], 2));
		pnts->center[X] /= mag;
			pnts->center[Y] /= mag;
			pnts->center[Z] /= mag;
			
	ft_putendl("________________________________________________________________");
	while (j < pnts->row)
	{
		i = 0;
		while (i < pnts->col)
		{
			mag = sqrt(pow(pnts->arr[j][i][X], 2) + pow(pnts->arr[j][i][Y], 2)
				   	+ pow(pnts->arr[j][i][Z], 2));
			printf("mag: %f\n", mag);
			pnts->arr[j][i][X] /= mag;
			pnts->arr[j][i][Y] /= mag;
			pnts->arr[j][i][Z] /= mag;
			printf("\ni: %zu\t j: %zu\n", i, j);
			printf("normallized pnts\nX: %f\tY: %f\tZ: %f\n",
				pnts->arr[j][i][X],
				pnts->arr[j][i][Y],
				pnts->arr[j][i][Z]);
			i++;
		}
		j++;
	}
	ft_putendl("________________________________________________________________");
}

void	rotate_X(void *param)
{
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	float temp_y;	

	fdf = (t_fdf *)param;
	j = 0;
	ft_putendl("rotate_X_test");
	while (j < fdf->pnts->row)
	{
		i = 0;
		while (i < fdf->pnts->col)
		{
			temp_y = fdf->pnts->arr[j][i][Y];
			fdf->pnts->arr[j][i][Y] = 
				fdf->pnts->arr[j][i][Y] * cos(fdf->rot_coeff) +
				fdf->pnts->arr[j][i][Z] * sin(fdf->rot_coeff);
			fdf->pnts->arr[j][i][Z] = 
				-temp_y * cos(fdf->rot_coeff) +
				fdf->pnts->arr[j][i][Z] * sin(fdf->rot_coeff);
			i++;
		}
		j++;
	}
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
	else if (keycode == BUT_min)
		mov_Z(param, fdf->mov_coeff);
	else if (keycode == BUT_plu)
		mov_Z(param, -fdf->mov_coeff);
	
	else if (keycode == 38)
		rotate_X(param);	
//	else if (keycode == 40)
//		rotate_Y(param);	
//	else if (keycode == 37)
//		rotate_Z(param);
	

	ft_putendl("exit_key________test");	
	print_fdf(fdf->mlx, fdf->win, get_pixel_arr(fdf->pnts));
	return(0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_fdf	*fdf;

		int		fd;
		if (!(fdf = malloc(sizeof(t_fdf))))
			return (-1);

		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			return (-1);
		if (!(fdf->mlx = mlx_init()))
			return (-1);
		if (!(fdf->win = mlx_new_window(fdf->mlx,
						IMG_WIDTH, IMG_HEIGHT, "mlx 42")))
			return (-1);
//		mlx_string_put (mlx, win, 50, 50, WHITE, "JOPA" );

		fdf->pnts = get_point_arr(fd);
		printf("POINT   col: %zu\trow: %zu\n", fdf->pnts->col,fdf->pnts->row);
		//normalize_pnts(fdf->pnts);
		fdf->pxls = get_pixel_arr(fdf->pnts);
		fdf->mov_coeff = 0.25;
		fdf->rot_coeff = 0.001;


//		set_rot_matr(fdf);
		print_fdf(fdf->mlx, fdf->win, fdf->pxls);

		ft_putendl("srakarm kashu2");

        //mlx_key_hook(fdf->win, exit_key, fdf);
        mlx_hook(fdf->win, 2, 5, exit_key, fdf);
		mlx_loop(fdf->mlx);
	}
	ft_putendl_fd("usage: fdf source file", 2);
	return(0);
}
