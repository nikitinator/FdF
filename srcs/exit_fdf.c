/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:30:10 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:47:20 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_fdf(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	while (i < fdf->pnts.row)
	{
		if (fdf->pnts.arr[i])
			free(fdf->pnts.arr[i]);
		if (fdf->pxls.arr[i])
			free(fdf->pxls.arr[i]);
		i++;
	}
	if (fdf->pnts.arr)
		free(fdf->pnts.arr);
	if (fdf->pxls.arr)
		free(fdf->pxls.arr);
	mlx_destroy_image(fdf->mlx, fdf->img.pnt_img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	while (1)
		;
	exit(1);
}
