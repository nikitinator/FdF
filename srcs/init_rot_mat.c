/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rot_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:19:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:06:29 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_rot_mat_x(t_fdf *fdf, double rot_coeff)
{
	static double	pre_rot_coeff;

	if (pre_rot_coeff != rot_coeff)
	{
		pre_rot_coeff = rot_coeff;
		fdf->rot_x[4] = cos(rot_coeff);
		fdf->rot_x[5] = -sin(rot_coeff);
		fdf->rot_x[7] = -fdf->rot_x[5];
		fdf->rot_x[8] = fdf->rot_x[4];
	}
}

void	set_rot_mat_y(t_fdf *fdf, double rot_coeff)
{
	static double	pre_rot_coeff;

	if (pre_rot_coeff != rot_coeff)
	{
		pre_rot_coeff = rot_coeff;
		fdf->rot_y[0] = cos(rot_coeff);
		fdf->rot_y[2] = sin(rot_coeff);
		fdf->rot_y[6] = -fdf->rot_y[2];
		fdf->rot_y[8] = fdf->rot_y[0];
	}
}

void	set_rot_mat_z(t_fdf *fdf, double rot_coeff)
{
	static double	pre_rot_coeff;

	if (pre_rot_coeff != rot_coeff)
	{
		pre_rot_coeff = rot_coeff;
		fdf->rot_z[0] = cos(rot_coeff);
		fdf->rot_z[1] = -sin(rot_coeff);
		fdf->rot_z[3] = -fdf->rot_z[1];
		fdf->rot_z[4] = fdf->rot_z[0];
	}
}

int		init_rot_mat(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < 9)
	{
		fdf->rot_x[i] = 0;
		fdf->rot_y[i] = 0;
		fdf->rot_z[i] = 0;
		fdf->scl[i] = 0;
	}
	fdf->rot_x[0] = 1;
	set_rot_mat_x(fdf, fdf->rot_coeff);
	fdf->rot_y[4] = 1;
	set_rot_mat_y(fdf, fdf->rot_coeff);
	fdf->rot_z[8] = 1;
	set_rot_mat_z(fdf, fdf->rot_coeff);
	return (1);
}
