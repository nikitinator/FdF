/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:39:16 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:04:21 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *fdf, int axis, double rot_coeff)
{
	t_point temp;

	ft_memcpy(temp, fdf->pnts.center, sizeof(t_point));
	if (axis == X)
		set_rot_mat_x(fdf, rot_coeff);
	else if (axis == Y)
		set_rot_mat_y(fdf, rot_coeff);
	else if (axis == Z)
		set_rot_mat_z(fdf, rot_coeff);
	transform_pnts(fdf, -fdf->pnts.center[X], -fdf->pnts.center[Y],
			-fdf->pnts.center[Z]);
	if (axis == X)
		mult_matr(fdf->rot_x, &fdf->pnts);
	else if (axis == Y)
		mult_matr(fdf->rot_y, &fdf->pnts);
	else if (axis == Z)
		mult_matr(fdf->rot_z, &fdf->pnts);
	transform_pnts(fdf, temp[X], temp[Y], temp[Z]);
}
