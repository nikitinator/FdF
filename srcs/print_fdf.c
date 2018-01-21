/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:28:55 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/21 18:40:24 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_fdf(void *mlx, void *win, t_img *img, t_pixarr *pxarr)
{
	size_t	i;
	size_t	j;

	ft_bzero(img->arr, IMG_HEIGHT * img->size_line);
	j = 0;
	while (j < pxarr->row - 1)
	{
		i = 0;
		while (i < pxarr->col - 1)
		{
			drw_line_bras(img, pxarr->arr[j][i], pxarr->arr[j][i + 1]);
			drw_line_bras(img, pxarr->arr[j][i], pxarr->arr[j + 1][i]);
			i++;
		}
		drw_line_bras(img, pxarr->arr[j][i], pxarr->arr[j + 1][i]);
		j++;
	}
	i = 0;
	while (i < pxarr->col - 1)
	{
		drw_line_bras(img, pxarr->arr[j][i], pxarr->arr[j][i + 1]);
		i++;
	}
	mlx_put_image_to_window(mlx, win, img->pnt_img, 0, 0); 
}
