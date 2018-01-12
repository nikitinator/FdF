/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_line_bras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:00:34 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/11 20:49:50 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//static	void	swap_int(int *a, int *b)
//{
//	int		temp;
//
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}


//void	drw_line_bras(void *mlx, void *win, t_pixel pixel1, t_pixel pixel2)
//{
//	int		x1;
//	int		y1;
//	int		deltaX; 
//	int		deltaY; 
//	int		signX;
//	int		signY;
//	int		error;
//	int		error2;
//
//	x1 = pixel1[X];
//	y1 = pixel1[Y];
//	deltaX = ABS(pixel2[X] - pixel1[X]);
//	deltaY = ABS(pixel2[Y] - pixel1[Y]);
//	error = deltaX - deltaY;
//	signX = pixel1[X] < pixel2[X] ? 1 : -1;
//	signY = pixel1[Y] < pixel2[Y] ? 1 : -1;
//	mlx_pixel_put(mlx, win, pixel2[X], pixel2[Y], WHITE);
//	while (x1 != pixel2[X] || y1 != pixel2[Y])
//	{
//		mlx_pixel_put(mlx, win, x1, y1, WHITE);
//		error2 = error << 2;
//		if (error2 > -deltaY)
//		{
//			error -= deltaY;
//			x1 += signX;
//		}
//		if (error2 < deltaX)
//		{
//			error += deltaX;
//			y1 += signY;
//		}
//	}	
//}

void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
{
	int		x1;
	int		y1;
	int		deltaX; 
	int		deltaY; 
	int		signX;
	int		signY;
	int		error;
	int		error2;

	x1 = pixel1[X];
	y1 = pixel1[Y];
	deltaX = ABS(pixel2[X] - pixel1[X]);
	deltaY = ABS(pixel2[Y] - pixel1[Y]);
	error = deltaX - deltaY;
	signX = pixel1[X] < pixel2[X] ? 1 : -1;
	signY = pixel1[Y] < pixel2[Y] ? 1 : -1;
	SET_PIX(pixel2[X], pixel2[Y], img, WHITE);
	while (x1 != pixel2[X] || y1 != pixel2[Y])
	{
		SET_PIX(x1, y1, img, WHITE);
		error2 = error << 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}	
}
