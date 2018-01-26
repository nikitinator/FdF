/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:48:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/26 16:04:27 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_on_pixarr(t_fdf *fdf, void (f)(t_point *))
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < fdf->pxls.row)
	{
		i = 0;
		while (i < fdf->pxls.col)
			(f)(fdf->pxls.arr[j][i]);
		j++;
	}
}

void	apply_on_pntarr(t_fdf *fdf , void (f)(t_point *))
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
			(f)(fdf->pxls.arr[j][i]);
		j++;
	}
}
