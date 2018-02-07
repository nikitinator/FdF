/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:53:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:03:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_pixel_arr(t_pntarr *parr, t_pixarr *pxarr)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < pxarr->row)
	{
		i = 0;
		while (i < pxarr->col)
		{
			pxarr->arr[j][i][X] = parr->arr[j][i][X];
			pxarr->arr[j][i][Y] = parr->arr[j][i][Y];
			i++;
		}
		j++;
	}
	return ;
}

void		init_pixel_arr(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	fdf->pxls.col = fdf->pnts.col;
	fdf->pxls.row = fdf->pnts.row;
	if (!(fdf->pxls.arr = malloc(fdf->pxls.row * sizeof(t_pixel *))))
		exit_fdf(fdf);
	j = 0;
	while (j < fdf->pxls.row)
	{
		i = 0;
		if (!(fdf->pxls.arr[j] = malloc((fdf->pxls.col) * sizeof(t_pixel))))
			exit_fdf(fdf);
		while (i < fdf->pxls.col)
		{
			fdf->pxls.arr[j][i][X] = fdf->pnts.arr[j][i][X];
			fdf->pxls.arr[j][i][Y] = fdf->pnts.arr[j][i][Y];
			fdf->pxls.arr[j][i][PXL_CLR] = fdf->pnts.arr[j][i][PNT_CLR];
			i++;
		}
		j++;
	}
	return ;
}
