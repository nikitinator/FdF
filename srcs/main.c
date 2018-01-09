/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/09 16:46:52 by snikitin         ###   ########.fr       */
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
	else if (keycode == BUT_J)
		rotate_X(param);	
	else if (keycode == BUT_K)
		rotate_Y(param);	
	else if (keycode == BUT_L)
		rotate_Z(param);
	
	ft_putendl("exit_key________test");	
	print_fdf(fdf->mlx, fdf->win, get_pixel_arr(fdf->pnts));
	return(0);
}

void	mult_matr(t_matr3 matrix, t_pntarr *pnts)
{
	size_t	i;
	size_t	j;
	double	temp[3];

////
//	temp[X] = matrix[0] * pnts->center[X] +
//		matrix[1] * pnts->center[Y] + matrix[2] * pnts->center[Z];
//	temp[Y] = matrix[3] * pnts->center[X] +
//		matrix[4] * pnts->center[Y] + matrix[5] * pnts->center[Z];
//	temp[Z] = matrix[6] * pnts->center[X] +
//		matrix[7] * pnts->center[Y] + matrix[8] * pnts->center[Z];
//	pnts->center[X] = temp[X];
//	pnts->center[Y] = temp[Y];
//	pnts->center[Z] = temp[Z];
////	
	j = 0;
	while(j < pnts->row)
	{
		i = 0;
		while (i < pnts->col)
		{	
			temp[X] = matrix[0] * pnts->arr[j][i][X] +
				matrix[1] * pnts->arr[j][i][Y] + matrix[2] * pnts->arr[j][i][Z];
			temp[Y] = matrix[3] * pnts->arr[j][i][X] +
				matrix[4] * pnts->arr[j][i][Y] + matrix[5] * pnts->arr[j][i][Z];
			temp[Z] = matrix[6] * pnts->arr[j][i][X] +
				matrix[7] * pnts->arr[j][i][Y] + matrix[8] * pnts->arr[j][i][Z];
			pnts->arr[j][i][X] = temp[X];
			pnts->arr[j][i][Y] = temp[Y];
			pnts->arr[j][i][Z] = temp[Z];
			i++;
		}
		j++;
	}
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

		fdf->pnts = get_point_arr(fd);
		//mov_X(fdf, -fdf->pnts->center[X]);
		//mov_Y(fdf, -fdf->pnts->center[Y]);
		////mov_Z(param, -fdf->pnts->center[Z]);

		//mov_X(fdf, IMG_WIDTH);
		//mov_Y(fdf, IMG_HEIGHT);
		printf("POINT   col: %zu\trow: %zu\n", fdf->pnts->col,fdf->pnts->row);
		//normalize_pnts(fdf->pnts);
		fdf->pxls = get_pixel_arr(fdf->pnts);
		fdf->mov_coeff = 0.25;
		fdf->rot_coeff = M_PI/180 * 3 ;


		init_rot_mat(fdf);
		print_fdf(fdf->mlx, fdf->win, fdf->pxls);

		ft_putendl("srakarm kashu2");

        //mlx_key_hook(fdf->win, exit_key, fdf);
        mlx_hook(fdf->win, 2, 5, exit_key, fdf);
		mlx_loop(fdf->mlx);
	}
	ft_putendl_fd("usage: fdf source file", 2);
	return(0);
}
