/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pnts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:58:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:04:10 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_pnts(t_fdf *fdf, double x, double y, double z)
{
	if (x)
	{
		apply_on_pntarr(fdf, x, mov_vec_x);
		fdf->pnts.center[X] += x;
	}
	if (y)
	{
		apply_on_pntarr(fdf, y, mov_vec_y);
		fdf->pnts.center[Y] += y;
	}
	if (z)
	{
		apply_on_pntarr(fdf, z, mov_vec_z);
		fdf->pnts.center[Z] += z;
	}
}
