/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:28:55 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 17:51:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_fdf(void *mlx, void *win, t_pixarr *pxarr)
{
	size_t	i;
	size_t	j;
/*
	j = 0;
	ft_putendl("lubitel§ govvna");

		while (j < pxarr->row)
		{
			i = 0;
			while (i < pxarr->col)
			{
				mlx_pixel_put(mlx, win, (int)(pxarr->arr[j][i][X]), (int)(pxarr->arr[j][i][Y]),
							  (int)(pxarr->arr[j][i][PXL_CLR]));
				i++;
			}
			j++;
		}
*/

			j = 0;
            while (j < pxarr->row)
            {
                i = 0;
                while (i < pxarr->col - 1)
                {
                    drw_line(mlx, win, pxarr->arr[j][i], pxarr->arr[j][i + 1]);
                    i++;
                }
                j++;
            }



           j = 0;
            while (j < pxarr->row - 1)
            {
                i = 0;
                while (i < pxarr->col)
                {
                    drw_line(mlx, win, pxarr->arr[j][i], pxarr->arr[j + 1][i]);
                    i++;
                }
                j++;
            }

}
