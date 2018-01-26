/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pnts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:58:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/26 16:36:46 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trans_inc_x(t_fdf *fdf)
{
	fdf->pnts.arr[j][i][X] += fdf->mov_coeff;
}

void	trans_inc_x(t_fdf *fdf)
{
	apply_on_pntarr(fdf, scale_inc_vec);
}

void	trans_inc_y(t_fdf *fdf)
{
	apply_on_pntarr(fdf, scale_inc_vec);
}

void	trans_inc_z(t_fdf *fdf)
{

}

void	transform_pnts(void *param, double x, double y, double z)
{
	if (x)
		mov_x(param, x);
	if (y)
		mov_y(param, y);
	if (z)
		mov_z(param, z);
}
