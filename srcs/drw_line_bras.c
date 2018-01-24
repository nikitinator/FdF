/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_line_bras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:00:34 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/24 18:23:45 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_data(t_drw_ln *v, t_pixel pixel1, t_pixel pixel2)
{
	v->t[X] = pixel1[X];
	v->t[Y] = pixel1[Y];
	v->t[PXL_CLR] = pixel1[PXL_CLR];
	v->delta_x = ABS(pixel2[X] - pixel1[X]);
	v->delta_y = ABS(pixel2[Y] - pixel1[Y]);
	v->sign_x = pixel1[X] < pixel2[X] ? 1 : -1;
	v->sign_y = pixel1[Y] < pixel2[Y] ? 1 : -1;
	if (v->delta_y > v->delta_x)
	{
		ft_swap_int(&v->delta_x, &v->delta_y);
		v->flag = 1;
	}
	else
		v->flag = 0;
	v->error = 2 * v->delta_y - v->delta_x; 
	v->c1.c_32 = pixel1[PXL_CLR];
	v->c2.c_32 = pixel2[PXL_CLR];
	if (v->delta_x)
	{
		v->m[R] = (v->c2.c_8[R] - v->c1.c_8[R])/v->delta_x;
		v->m[G] = (v->c2.c_8[G] - v->c1.c_8[G])/v->delta_x;
		v->m[B] = (v->c2.c_8[B] - v->c1.c_8[B])/v->delta_x;
	}
	v->c[R] = v->c1.c_8[R]; 
	v->c[G] = v->c1.c_8[G];
	v->c[B] = v->c1.c_8[B];
}

static void	change_color(t_drw_ln *v)
{
	v->c[R] += v->m[R];
	v->c[G] += v->m[G];
	v->c[B] += v->m[B];
	v->c1.c_8[R] = v->c[R];
	v->c1.c_8[G] = v->c[G];
	v->c1.c_8[B] = v->c[B];
}

void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
{
	int			i;
	t_drw_ln	v;

	i = 0;
	init_data(&v, pixel1, pixel2);
	if (!v.delta_x && !v.delta_y)
		return ;
	while (i <= v.delta_x)
	{
		SET_PIX(v.t[X], v.t[Y], img, v.c1.c_32);
		change_color(&v);
		while (v.error > 0)
		{
			if (v.flag)
				v.t[X] += v.sign_x;
			else
				v.t[Y] += v.sign_y;
			v.error = v.error - 2 * v.delta_x;
		}	
		if (v.flag)
			v.t[Y] += v.sign_y;
		else
			v.t[X] += v.sign_x;
		v.error = v.error + 2 * v.delta_y;
		i++;
	}
}



//_____________________________________________________________________________



//static void	init_data(t_drw_ln *v, t_pixel pixel1, t_pixel pixel2)
//{
//	v->t[X] = pixel1[X];
//	v->t[Y] = pixel1[Y];
//	v->t[PXL_CLR] = pixel1[PXL_CLR];
//	v->delta_x = ABS(pixel2[X] - pixel1[X]);
//	v->delta_y = ABS(pixel2[Y] - pixel1[Y]);
//	v->error = v->delta_x - v->delta_y;
//	v->sign_x = pixel1[X] < pixel2[X] ? 1 : -1;
//	v->sign_y = pixel1[Y] < pixel2[Y] ? 1 : -1;
//	v->pix_num = sqrt(pow(v->delta_x, 2) + pow(v->delta_y, 2));
//	v->c1.c_32 = pixel1[PXL_CLR];
//	v->c2.c_32 = pixel2[PXL_CLR];
//	if (v->pix_num)
//	{
//		v->m[R] = (v->c2.c_8[R] - v->c1.c_8[R])/v->pix_num ;
//		v->m[G] = (v->c2.c_8[G] - v->c1.c_8[G])/v->pix_num ;
//		v->m[B] = (v->c2.c_8[B] - v->c1.c_8[B])/v->pix_num ;
//		
//		//printf("(v->c1.c_8[R] - v->c2.c_8[R])%d\n",(v->c1.c_8[R] - v->c2.c_8[R]));
//		//printf("(v->c1.c_8[G] - v->c2.c_8[G])%d\n",(v->c1.c_8[G] - v->c2.c_8[G]));
//		//printf("(v->c1.c_8[B] - v->c2.c_8[B])%d\n",(v->c1.c_8[B] - v->c2.c_8[B]));
//		//
//		//printf("pix_num %f\n", v->pix_num);
//		//printf("v->m[R] %f\n", v->m[R]);
//		//printf("v->m[G] %f\n", v->m[G]);
//		//printf("v->m[B] %f\n\n", v->m[B]);
//	}
//	v->c[R] = v->c1.c_8[R]; 
//	v->c[G] = v->c1.c_8[G];
//	v->c[B] = v->c1.c_8[B];
//}
//
//static void	change_color(t_drw_ln *v)
//{
//	v->c[R] += v->m[R];
//	v->c[G] += v->m[G];
//	v->c[B] += v->m[B];
//	v->c1.c_8[R] = v->c[R];
//	v->c1.c_8[G] = v->c[G];
//	v->c1.c_8[B] = v->c[B];
//}
//
//void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
//{
//	t_drw_ln	v;
//
//	init_data(&v, pixel1, pixel2);
//	if (!v.delta_x && !v.delta_y)
//		return ;
//	CHK_PIX(pixel2[X], pixel2[Y])SET_PIX(pixel2[X], pixel2[Y], img, pixel2[PXL_CLR])
//	while (v.t[X] != pixel2[X] || v.t[Y] != pixel2[Y])
//	{
//		CHK_PIX(v.t[X], v.t[Y])SET_PIX(v.t[X], v.t[Y], img, v.c1.c_32)
//		change_color(&v);
//		v.error_2 = v.error << 2;
//		if (v.error_2 > -v.delta_y)
//		{
//			v.error -= v.delta_y;
//			v.t[X] += v.sign_x;
//		}
//		if (v.error_2 < v.delta_x)
//		{
//			v.error += v.delta_x;
//			v.t[Y] += v.sign_y;
//		}
//	}	
//}
//



//_____________________________________________________________________________




//static void	init_data(t_drw_ln *v, t_pixel pixel1, t_pixel pixel2) //{
//	v->t[X] = pixel1[X];
//	v->t[Y] = pixel1[Y];
//	v->t[PXL_CLR] = pixel1[PXL_CLR];
//	v->delta_x = ABS(pixel2[X] - pixel1[X]);
//	v->delta_y = ABS(pixel2[Y] - pixel1[Y]);
//	v->error = v->delta_x - v->delta_y;
//	v->sign_x = pixel1[X] < pixel2[X] ? 1 : -1;
//	v->sign_y = pixel1[Y] < pixel2[Y] ? 1 : -1;
//}
//
//void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
//{
//	t_drw_ln	v;
//
//	init_data(&v, pixel1, pixel2);
//	if (!v.delta_x && !v.delta_y)
//		return ;
//	CHK_PIX(pixel2[X], pixel2[Y])SET_PIX(pixel2[X], pixel2[Y], img, pixel2[PXL_CLR])
//	while (v.t[X] != pixel2[X] || v.t[Y] != pixel2[Y])
//	{
//		CHK_PIX(v.t[X], v.t[Y])SET_PIX(v.t[X], v.t[Y], img, v.t[PXL_CLR])
//		v.error_2 = v.error << 2;
//		if (v.error_2 > -v.delta_y)
//		{
//			v.error -= v.delta_y;
//			v.t[X] += v.sign_x;
//		}
//		if (v.error_2 < v.delta_x)
//		{
//			v.error += v.delta_x;
//			v.t[Y] += v.sign_y;
//		}
//	}	
//}


//_____________________________________________________________________________


//void	drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
//{
//	t_pixel temp;
//	int		delta_x; 
//	int		delta_y; 
//	int		sign_x;
//	int		sign_y;
//	int		error;
//	int		error_2;
//
//	temp[X] = pixel1[X];
//	temp[Y] = pixel1[Y];
//	temp[PXL_CLR] = pixel1[PXL_CLR];
//	delta_x = ABS(pixel2[X] - pixel1[X]);
//	delta_y = ABS(pixel2[Y] - pixel1[Y]);
//	error = delta_x - delta_y;
//	sign_x = pixel1[X] < pixel2[X] ? 1 : -1;
//	sign_y = pixel1[Y] < pixel2[Y] ? 1 : -1;
//	if (!delta_x && !delta_y)
//		return ;
//	CHK_PIX(pixel2[X], pixel2[Y])SET_PIX(pixel2[X], pixel2[Y], img, pixel2[PXL_CLR])
//	while (temp[X] != pixel2[X] || temp[Y] != pixel2[Y])
//	{
//		CHK_PIX(temp[X], temp[Y])SET_PIX(temp[X], temp[Y], img, temp[PXL_CLR])
//		error_2 = error << 2;
//		if (error_2 > -delta_y)
//		{
//			error -= delta_y;
//			temp[X] += sign_x;
//		}
//		if (error_2 < delta_x)
//		{
//			error += delta_x;
//			temp[Y] += sign_y;
//		}
//	}	
//}


//printf("c2R:%x\tc2G:%x\tc2B:%x\t\n", v->c2.col_b[R],v->c2.col_b[G],v->c2.col_b[B]);
//printf("_______________________________\n");
//printf("c1R:%x\tc1G:%x\tc1B:%x\t\n", v->c1.col_b[R],v->c1.col_b[G],v->c1.col_b[B]);
//printf("c2R:%x\tc2G:%x\tc2B:%x\t\n", v->c2.col_b[R],v->c2.col_b[G],v->c2.col_b[B]);
//printf("pix_num %f\n\n",v->pix_num)
