/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:53:02 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/21 17:07:59 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
t_pixarr	*get_pixel_arr(t_pntarr *parr)
{
	t_pixarr	*pxarr;
	size_t	i;
	size_t	j;

	pxarr = malloc(sizeof(t_pixarr));
	pxarr->col = parr->col;
	pxarr->row = parr->row;
	pxarr->arr = malloc(pxarr->row * sizeof(t_pixel *));

	j = 0;
        while (j < pxarr->row)
        {
            i = 0;
            pxarr->arr[j] = malloc((pxarr->col) * sizeof(t_pixel));
		while (i < pxarr->col)
		{
			pxarr->arr[j][i][X] = parr->arr[j][i][X] / -parr->arr[j][i][Z];
			pxarr->arr[j][i][Y] = parr->arr[j][i][Y] / -parr->arr[j][i][Z];
			pxarr->arr[j][i][X] = ((pxarr->arr[j][i][X] + 1) / 2) * (512);
			pxarr->arr[j][i][Y] = ((pxarr->arr[j][i][Y] + 1) / 2) * (512);

			printf("x: %f, y: %f, z:%f\n",
					parr->arr[j][i][X], parr->arr[j][i][Y], parr->arr[j][i][Z]);

        	printf("i:%zu j:%zu x:%f y:%f\n\n", i, j, pxarr->arr[j][i][X], pxarr->arr[j][i][Y]);
			pxarr->arr[j][i][PXL_CLR] = parr->arr[j][i][PNT_CLR];
			i++;
		}
		j++;
	}
	ft_putendl("kakashka");
	return (pxarr);
}
