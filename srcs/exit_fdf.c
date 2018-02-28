/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:30:10 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/28 19:17:42 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_fdf(t_fdf *fdf)
{
	size_t		i;

	i = 0;
	(void)fdf;
	while (i < fdf->pnts.row)
	{
		if (fdf->pnts.arr && fdf->pnts.arr[i])
			free(fdf->pnts.arr[i]);
		if (fdf->pxls.arr && fdf->pxls.arr[i])
			free(fdf->pxls.arr[i]);
		i++;
	}
	if (fdf->pnts.arr)
		free(fdf->pnts.arr);
	if (fdf->pxls.arr)
		free(fdf->pxls.arr);
	if (fdf->img.pnt_img)
		mlx_destroy_image(fdf->mlx, fdf->img.pnt_img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	exit(1);
}
