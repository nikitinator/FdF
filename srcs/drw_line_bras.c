/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_line_bras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:00:34 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/16 21:10:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//
//void	drw_line_bras2(t_img *img, t_pixel pixel1, t_pixel pixel2)
//{
//	t_pixel temp;
//	int		color_step;
//	int		deltaX; 
//	int		deltaY; 
//	int		signX;
//	int		signY;
//	int		error;
//	int		error2;
//
//	temp[PXL_CLR] = pixel1[PXL_CLR];
//	temp[X] = pixel1[X];
//	temp[Y] = pixel1[Y];
//	temp[PXL_CLR] = pixel2[PXL_CLR];
//	deltaX = ABS(pixel2[X] - pixel1[X]);
//	deltaY = ABS(pixel2[Y] - pixel1[Y]);
//	error = deltaX - deltaY;
//	signX = pixel1[X] < pixel2[X] ? 1 : -1;
//	signY = pixel1[Y] < pixel2[Y] ? 1 : -1;
//	color_step = pixel2[PXL_CLR] - temp[PXL_CLR];
//	if (!deltaX && !deltaY)
//		return ;
//	color_step /= deltaX > deltaY ? deltaX : deltaY;
//	CHK_PIX(pixel2[X], pixel2[Y])SET_PIX(pixel2[X], pixel2[Y], img, pixel2[PXL_CLR])
//	while (temp[X] != pixel2[X] || temp[Y] != pixel2[Y])
//	{
//		CHK_PIX(temp[X], temp[Y])SET_PIX(temp[X], temp[Y], img, temp[PXL_CLR])
//		temp[PXL_CLR] += color_step;
//		error2 = error << 2;
//		if (error2 > -deltaY)
//		{
//			error -= deltaY;
//			temp[X] += signX;
//		}
//		if (error2 < deltaX)
//		{
//			error += deltaX;
//			temp[Y] += signY;
//		}
//	}	
//}
//

static void	init_data(t_drw_ln *data, t_pixel pixel1, t_pixel pixel2)
{
	int		temp;

	temp = 0;
	data->c1.col_i = pixel1[PIX_COL];
	data->c2.col_i = pixel2[PIX_COL];
	data->dx = ABS(pixel2[X] - pixel1[X]);
	data->dy = ABS(pixel2[Y] - pixel1[Y]);
	data->s1 = data.dx >= 0 ? 1 : -1;
	data->s2 = data.dy >= 0 ? 1 : -1;
	if (data->dx > data->dy)
	{
		temp = data->dy;
		data->dy = data->dx;
		data->dx = data->temp;
	}
	data->c2.col_b[R] = data->c2.col_b[R] - data->c1.col_b[R];
	data->c2.col_b[G] = data->c2.col_b[G] - data->c1.col_b[G];
	data->c2.col_b[B] = data->c2.col_b[B] - data->c1.col_b[B];
	data->c2.col_b[R] = data->c2.col_b[R] / data->dx;
	data->c2.col_b[G] = data->c2.col_b[G] / data->dx;
	data->c2.col_b[B] = data->c2.col_b[B] / data->dx;
	flag = dy > dx ? 1 : 0;
	data->error = (data->dy << 2) - data->dx;
}

void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
{
	t_drw_ln	data;
	size_t		i;

	i = 0;
	init_data(&data, pixel1, pixel2);
	while (i < data.dx)
	{
		SET_PIX(pixel1[X], pixel1[Y], img, data->c1.col_i)
		while (error >= 0)
		{
			if (data->flag)
				pixel1[X] += data->s1;
			else
				pixel1[Y] += data->s2;
			error = error - (dx << 2);
		}
		if (flag)
			pixel1[Y] += data->s2;
		else
			pixel1[X] += data->s1;
		error = error + (dy << 2);
	}
}
