/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_line_bras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:00:34 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/17 21:53:40 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//
//static void	init_data(t_drw_ln *v, t_pixel pixel1, t_pixel pixel2)
//{
//	v->c1.col_i = pixel1[PXL_CLR];
//	v->c2.col_i = pixel2[PXL_CLR];
//	v->delta_X = ABS(pixel2[X] - pixel1[X]);
//	v->delta_Y = ABS(pixel2[Y] - pixel1[Y]);
//	v->sign_X = pixel1[X] < pixel2[X] ? 1 : -1;
//	v->sign_Y = pixel1[Y] < pixel2[Y] ? 1 : -1;
//	v->pix_num = v->delta_X > v->delta_Y ? v->delta_X : v->delta_Y;
//	v->error = v->delta_X - v->delta_Y;
//	if (v->pix_num)
//	{
//		v->m[R] = (v->c2.col_b[R] - v->c1.col_b[R])/v->pix_num -1;
//		v->m[G] = (v->c2.col_b[G] - v->c1.col_b[G])/v->pix_num -1;
//		v->m[B] = (v->c2.col_b[B] - v->c1.col_b[B])/v->pix_num -1;
//	}
//}	

void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
{
	t_pixel temp;
	int		delta_X; 
	int		delta_Y; 
	int		sign_X;
	int		sign_Y;
	int		error;
	
	int		error_2;
	int		c_error;
	int		c_error_2;
	t_color	c1;
	t_color	c2;
	c1.c_32 = pixel1[PXL_CLR];
	c2.c_32 = pixel2[PXL_CLR];
	delta_err_R = c2.c_8[R] - c1.c_8[R]; 
	delta_err_G = (c2.c_8[G] - c1.c_8[R])/num_pix; 
	delta_err_R = (c2.c_8[R] - c1.c_8[R])/num_pix; 
	



	temp[X] = pixel1[X];
	temp[Y] = pixel1[Y];
	temp[PXL_CLR] = pixel1[PXL_CLR];
	delta_X = ABS(pixel2[X] - pixel1[X]);
	delta_Y = ABS(pixel2[Y] - pixel1[Y]);
	error = delta_X - delta_Y;
	sign_X = pixel1[X] < pixel2[X] ? 1 : -1;
	sign_Y = pixel1[Y] < pixel2[Y] ? 1 : -1;
	if (!delta_X && !delta_Y)
		return ;
	CHK_PIX(pixel2[X], pixel2[Y])SET_PIX(pixel2[X], pixel2[Y], img, pixel2[PXL_CLR])
	while (temp[X] != pixel2[X] || temp[Y] != pixel2[Y])
	{
		CHK_PIX(temp[X], temp[Y])SET_PIX(temp[X], temp[Y], img, temp[PXL_CLR])
		error_2 = error << 2;
		if (error_2 > -delta_Y)
		{
			error -= delta_Y;
			temp[X] += sign_X;
		}
		if (error_2 < delta_X)
		{
			error += delta_X;
			temp[Y] += sign_Y;
		}
	}	
}
//
//void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
//{
//	t_pixel temp;
//	int		delta_X; 
//	int		delta_Y; 
//	int		sign_X;
//	int		sign_Y;
//	int		error;
//	int		error_2;
//
//	temp[X] = pixel1[X];
//	temp[Y] = pixel1[Y];
//	temp[PXL_CLR] = pixel1[PXL_CLR];
//	delta_X = ABS(pixel2[X] - pixel1[X]);
//	delta_Y = ABS(pixel2[Y] - pixel1[Y]);
//	error = delta_X - delta_Y;
//	sign_X = pixel1[X] < pixel2[X] ? 1 : -1;
//	sign_Y = pixel1[Y] < pixel2[Y] ? 1 : -1;
//	if (!delta_X && !delta_Y)
//		return ;
//	CHK_PIX(pixel2[X], pixel2[Y])SET_PIX(pixel2[X], pixel2[Y], img, pixel2[PXL_CLR])
//	while (temp[X] != pixel2[X] || temp[Y] != pixel2[Y])
//	{
//		CHK_PIX(temp[X], temp[Y])SET_PIX(temp[X], temp[Y], img, temp[PXL_CLR])
//		error_2 = error << 2;
//		if (error_2 > -delta_Y)
//		{
//			error -= delta_Y;
//			temp[X] += sign_X;
//		}
//		if (error_2 < delta_X)
//		{
//			error += delta_X;
//			temp[Y] += sign_Y;
//		}
//	}	
//}
//
//printf("c2R:%x\tc2G:%x\tc2B:%x\t\n", v->c2.col_b[R],v->c2.col_b[G],v->c2.col_b[B]);
//printf("_______________________________\n");
//printf("c1R:%x\tc1G:%x\tc1B:%x\t\n", v->c1.col_b[R],v->c1.col_b[G],v->c1.col_b[B]);
//printf("c2R:%x\tc2G:%x\tc2B:%x\t\n", v->c2.col_b[R],v->c2.col_b[G],v->c2.col_b[B]);
//printf("pix_num %f\n\n",v->pix_num)
