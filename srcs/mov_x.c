/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:56:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:05:12 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mov_vec_x(t_point *p, double n)
{
	(*p)[X] += n;
}

void	mov_incr_x(t_fdf *fdf)
{
	apply_on_pntarr(fdf, fdf->mov_coeff, mov_vec_x);
	fdf->pnts.center[X] += fdf->mov_coeff;
}

void	mov_decr_x(t_fdf *fdf)
{
	apply_on_pntarr(fdf, -fdf->mov_coeff, mov_vec_x);
	fdf->pnts.center[X] -= fdf->mov_coeff;
}
