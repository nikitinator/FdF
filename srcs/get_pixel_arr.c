/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:53:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/21 18:54:36 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//

void	get_persp_arr(t_pntarr *parr, t_pixarr *pxarr)
{
	size_t	i;
	size_t	j;
	float	coeff;
	double	f_pix[2];
	f_pix[X] = 1;
	f_pix[Y] = 1;
			
	coeff = 5;// IMG_WIDTH /parr->arr[0][0][X];
	j = 0;
	while (j < pxarr->row)
	{
		i = 0;
		while (i < pxarr->col)
		{
			if (parr->arr[j][i][Z] != 0)
			{
				f_pix[X] = parr->arr[j][i][X] / -(parr->arr[j][i][Z]);
				f_pix[Y] = parr->arr[j][i][Y] / -(parr->arr[j][i][Z]);
			 
			f_pix[X] *= coeff;
			f_pix[Y] *= coeff;
			
			f_pix[X] += IMG_WIDTH / 2;
			f_pix[Y] += IMG_HEIGHT / 2;

			pxarr->arr[j][i][X] = f_pix[X];
			pxarr->arr[j][i][Y] = f_pix[Y];
	
//			printf("x: %f, y: %f, z:%f\n",
//					parr->arr[j][i][X], parr->arr[j][i][Y], parr->arr[j][i][Z]);
//			printf("i:%zu j:%zu x:%d y:%d\n\n",
//					i, j, pxarr->arr[j][i][X], pxarr->arr[j][i][Y]);
//			
				i++;
			}
		}
		j++;
	}
	ft_putendl("kakashka");
	return ;
}


void	get_ort_arr(t_pntarr *parr, t_pixarr *pxarr)
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
				pxarr->arr[j][i][X] = parr->arr[j][i][X];
				pxarr->arr[j][i][Y] = parr->arr[j][i][Y];

			//	printf("x: %f, y: %f, z:%f\n",
			//			parr->arr[j][i][X], parr->arr[j][i][Y], parr->arr[j][i][Z]);
			//	printf("i:%zu j:%zu x:%d y:%d\n\n",
			//		i, j, pxarr->arr[j][i][X], pxarr->arr[j][i][Y]);

				i++;
		}
		j++;
	}
	ft_putendl("kakashka");
	return ;
}

void	get_pixel_arr(t_pntarr *parr, t_pixarr *pxarr)
{
	if (pxarr->pr_type == ORTOGONAL)
		get_ort_arr(parr, pxarr);
	else
		get_persp_arr(parr, pxarr);
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
