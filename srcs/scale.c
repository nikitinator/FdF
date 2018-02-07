/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:43:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:04:29 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	scale_incr_vec(t_point *p, double n)
{
	(*p)[X] = (*p)[X] * n;
	(*p)[Y] = (*p)[Y] * n;
	(*p)[Z] = (*p)[Z] * n;
}

static void	scale_decr_vec(t_point *p, double n)
{
	(*p)[X] = (*p)[X] / n;
	(*p)[Y] = (*p)[Y] / n;
	(*p)[Z] = (*p)[Z] / n;
}

void		scale_incr(t_fdf *fdf)
{
	t_point	temp;

	ft_memcpy(temp, fdf->pnts.center, sizeof(t_point));
	transform_pnts(fdf, -fdf->pnts.center[X], -fdf->pnts.center[Y],
			-fdf->pnts.center[Z]);
	apply_on_pntarr(fdf, fdf->scl_coeff, scale_incr_vec);
	transform_pnts(fdf, temp[X], temp[Y], temp[Z]);
}

void		scale_decr(t_fdf *fdf)
{
	t_point temp;

	ft_memcpy(temp, fdf->pnts.center, sizeof(t_point));
	transform_pnts(fdf, -fdf->pnts.center[X], -fdf->pnts.center[Y],
			-fdf->pnts.center[Z]);
	apply_on_pntarr(fdf, fdf->scl_coeff, scale_decr_vec);
	transform_pnts(fdf, temp[X], temp[Y], temp[Z]);
}
