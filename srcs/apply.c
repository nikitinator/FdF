/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:48:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:03:06 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_on_pxlarr(t_fdf *fdf, int clr, int val,
		void (f)(t_pixel *, int clr, int val))
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < fdf->pxls.row)
	{
		i = 0;
		while (i < fdf->pxls.col)
		{
			(f)(&fdf->pxls.arr[j][i], clr, val);
			i++;
		}
		j++;
	}
}

void	apply_on_pntarr(t_fdf *fdf, double n, void (f)(t_point *, double))
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
		{
			(f)(&fdf->pnts.arr[j][i], n);
			i++;
		}
		j++;
	}
}
