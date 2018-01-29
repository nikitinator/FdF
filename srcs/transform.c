/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pnts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:58:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/29 15:14:04 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trans_inc_x_vec(t_fdf *fdf)
{
	fdf->pnts.arr[j][i][X] += fdf->mov_coeff;
}

void	trans_inc_y_vec(t_fdf *fdf)
{
	fdf->pnts.arr[j][i][Y] += fdf->mov_coeff;
}

void	trans_inc_z_vec(t_fdf *fdf)
{
	fdf->pnts.arr[j][i][Z] += fdf->mov_coeff;
}

void	trans_inc_x(t_fdf *fdf)
{
	apply_on_pntarr(fdf, trans_inc_x_vec);
}

void	trans_inc_y(t_fdf *fdf)
{
	apply_on_pntarr(fdf, trans_inc_y_vec);
}

void	trans_inc_z(t_fdf *fdf)
{
	apply_on_pntarr(fdf, trans_inc_z_vec);
}



void	trans_dec_x_vec(t_fdf *fdf)
{
	fdf->pnts.arr[j][i][X] += fdf->mov_coeff;
}

void	trans_dec_y_vec(t_fdf *fdf)
{
	fdf->pnts.arr[j][i][Y] += fdf->mov_coeff;
}

void	trans_dec_z_vec(t_fdf *fdf)
{
	fdf->pnts.arr[j][i][Z] += fdf->mov_coeff;
}

void	trans_dec_x(t_fdf *fdf)
{
	apply_on_pntarr(fdf, trans_dec_x_vec);
}

void	trans_dec_y(t_fdf *fdf)
{
	apply_on_pntarr(fdf, trans_dec_y_vec);
}

void	trans_dec_z(t_fdf *fdf)
{
	apply_on_pntarr(fdf, trans_dec_z_vec);
}


void	transform_pnts(void *param, double x, double y, double z)
{
	if (x > 0)
		trans_inc_x(param);
	if (x < 0)
		trans_dec_x(param);
	if (y > 0)
		trans_inc_y(param);
	if (y < 0)
		trans_dec_y(param);
	if (z > 0)
		trans_inc_z(param);
	if (z < 0)
		trans_dec_z(param);
}
