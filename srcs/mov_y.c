/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:03:57 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:05:19 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mov_vec_y(t_point *p, double n)
{
	(*p)[Y] += n;
}

void	mov_incr_y(t_fdf *fdf)
{
	apply_on_pntarr(fdf, fdf->mov_coeff, mov_vec_y);
	fdf->pnts.center[Y] += fdf->mov_coeff;
}

void	mov_decr_y(t_fdf *fdf)
{
	apply_on_pntarr(fdf, -fdf->mov_coeff, mov_vec_y);
	fdf->pnts.center[Y] -= fdf->mov_coeff;
}
