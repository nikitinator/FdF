/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:52:48 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/11 16:54:24 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	drw_line(void *mlx, void *win, t_pxl *pixel1, t_pxl *pixel2)
{
	float	i;
	int		x;
	int		y;

	i = 0.;

	while (i < 1.)
	{
		x = pixel1->x * (1. - i) + pixel2->x * i;
		y = pixel1->y * (1. - i) + pixel2->y * i;
		mlx_pixel_put(mlx, win, x, y, pixel1->color);
		i += .001;
	}
}
