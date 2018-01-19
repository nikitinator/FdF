/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:53:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/19 16:21:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
void	get_pixel_arr(t_pntarr *parr, t_pixarr *pxarr)
{
	size_t	i;
	size_t	j;

	//printf("center: \n");
	//printf("x: %f, y: %f, z:%f\n\n",
	//			parr->center[X], parr->center[Y], parr->center[Z]);
	j = 0;
	while (j < pxarr->row)
	{
		i = 0;
		while (i < pxarr->col)
		{
			//if (fdf->pr_type % 2)
			//{
			//	pxarr->arr[j][i][X] = parr->arr[j][i][X] / -(parr->arr[j][i][Z]);
			//	pxarr->arr[j][i][Y] = parr->arr[j][i][Y] / -(parr->arr[j][i][Z]);
			//	pxarr->arr[j][i][PXL_CLR] = parr->arr[j][i][PXL_CLR];
			//}
			//else
			//{
				pxarr->arr[j][i][X] = parr->arr[j][i][X];
				pxarr->arr[j][i][Y] = parr->arr[j][i][Y];
				pxarr->arr[j][i][PXL_CLR] = pxarr->arr[j][i][PXL_CLR];
			//}
			//printf("x: %f, y: %f, z:%f\n",
			//		parr->arr[j][i][X], parr->arr[j][i][Y], parr->arr[j][i][Z]);
			//printf("i:%zu j:%zu x:%d y:%d\n\n",
			//		i, j, pxarr->arr[j][i][X], pxarr->arr[j][i][Y]);
				i++;
		}
		j++;
	}
	ft_putendl("kakashka");
	return ;
}

void	init_pixel_arr(t_fdf *fdf)
{
	t_pntarr		*parr;
	t_pixarr		*pxarr;

	pxarr = &fdf->pxls;
	parr = &fdf->pnts;
	size_t	i;
	size_t	j;

	pxarr->col = parr->col;
	pxarr->row = parr->row;
	pxarr->arr = malloc(pxarr->row * sizeof(t_pixel *));
	//printf("center: \n");
	//printf("x: %f, y: %f, z:%f\n\n",
	//			parr->center[X], parr->center[Y], parr->center[Z]);

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
				pxarr->arr[j][i][PXL_CLR] = parr->arr[j][i][PNT_CLR];
			}
			else
			{
				pxarr->arr[j][i][X] = parr->arr[j][i][X];
				pxarr->arr[j][i][Y] = parr->arr[j][i][Y];
				pxarr->arr[j][i][PXL_CLR] = parr->arr[j][i][PNT_CLR];
			}
			//printf("x: %f, y: %f, z:%f\n",
			//		parr->arr[j][i][X], parr->arr[j][i][Y], parr->arr[j][i][Z]);
			//printf("i:%zu j:%zu x:%d y:%d\n\n",
			//		i, j, pxarr->arr[j][i][X], pxarr->arr[j][i][Y]);
				i++;
		}
		j++;
	}
	ft_putendl("kakashka");
	return ;
}
