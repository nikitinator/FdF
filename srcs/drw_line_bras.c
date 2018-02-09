/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_line_bras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:00:34 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/09 11:24:39 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_color(t_drw_ln *v)
{
	if (v->delta_x)
	{
		v->m[R] = (v->c2.c_8[R] - v->c1.c_8[R]) / v->delta_x;
		v->m[G] = (v->c2.c_8[G] - v->c1.c_8[G]) / v->delta_x;
		v->m[B] = (v->c2.c_8[B] - v->c1.c_8[B]) / v->delta_x;
	}
	v->c[R] = v->c1.c_8[R];
	v->c[G] = v->c1.c_8[G];
	v->c[B] = v->c1.c_8[B];
}

static void	init_data(t_drw_ln *v, t_pixel pixel1, t_pixel pixel2)
{
	v->t[X] = pixel1[X];
	v->t[Y] = pixel1[Y];
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
	init_color(v);
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

void		drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2)
{
	int			i;
	t_drw_ln	v;

	i = -1;
	init_data(&v, pixel1, pixel2);
	if (!v.delta_x && !v.delta_y)
		return ;
	while (++i <= v.delta_x)
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
	}
}
