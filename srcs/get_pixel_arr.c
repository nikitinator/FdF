/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:53:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/11 19:09:15 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
t_pixarr	*get_pixel_arr(t_fdf *fdf)
{
	t_pixarr	*pxarr;
	t_pntarr		*parr;

	parr = fdf->pnts;
	size_t	i;
	size_t	j;

	pxarr = malloc(sizeof(t_pixarr));
	pxarr->col = parr->col;
	pxarr->row = parr->row;
	pxarr->arr = malloc(pxarr->row * sizeof(t_pixel *));
	printf("center: \n");
	printf("x: %f, y: %f, z:%f\n\n",
				parr->center[X], parr->center[Y], parr->center[Z]);

	if (fdf->pr_type % 2)
	{
			pxarr->center[X] = parr->center[X];
			pxarr->center[Y] = parr->center[Y];
	}
	else
	{
		pxarr->center[X] = parr->center[X];// / -parr->center[Z];
		pxarr->center[Y] = parr->center[Y];// / -parr->center[Z];
	}
	j = 0;
	while (j < pxarr->row)
	{
		i = 0;
		pxarr->arr[j] = malloc((pxarr->col) * sizeof(t_pixel));
		while (i < pxarr->col)
		{
			if (fdf->pr_type % 2)
			{
				pxarr->arr[j][i][X] = parr->arr[j][i][X] / -(parr->arr[j][i][Z]);
				pxarr->arr[j][i][Y] = parr->arr[j][i][Y] / -(parr->arr[j][i][Z]);
			}
			else
			{
				pxarr->arr[j][i][X] = parr->arr[j][i][X];
				pxarr->arr[j][i][Y] = parr->arr[j][i][Y];
			}
			printf("x: %f, y: %f, z:%f\n",
					parr->arr[j][i][X], parr->arr[j][i][Y], parr->arr[j][i][Z]);
			printf("i:%zu j:%zu x:%d y:%d\n\n",
					i, j, pxarr->arr[j][i][X], pxarr->arr[j][i][Y]);
			pxarr->arr[j][i][PXL_CLR] = parr->arr[j][i][PNT_CLR];
				i++;
		}
		j++;
	}
	ft_putendl("kakashka");
	return (pxarr);
}
