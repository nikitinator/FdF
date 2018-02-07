/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:03:12 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:05:26 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mov_vec_z(t_point *p, double n)
{
	(*p)[Z] += n;
}

void	mov_incr_z(t_fdf *fdf)
{
	apply_on_pntarr(fdf, fdf->mov_coeff, mov_vec_z);
	fdf->pnts.center[Z] += fdf->mov_coeff;
}

void	mov_decr_z(t_fdf *fdf)
{
	apply_on_pntarr(fdf, -fdf->mov_coeff, mov_vec_z);
	fdf->pnts.center[Z] -= fdf->mov_coeff;
}
