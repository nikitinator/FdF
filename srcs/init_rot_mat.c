/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rot_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:19:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/16 16:39:51 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_rot_mat_X(t_fdf *fdf, double rot_coeff)
{
	static double	pre_rot_coeff;

	if (pre_rot_coeff != rot_coeff)
	{
		pre_rot_coeff = rot_coeff;
		fdf->rot_X[4] = cos(rot_coeff);	
		fdf->rot_X[5] = -sin(rot_coeff);	
		fdf->rot_X[7] = -fdf->rot_X[5];	
		fdf->rot_X[8] = fdf->rot_X[4];	
	}
}

void	set_rot_mat_Y(t_fdf *fdf, double rot_coeff)
{	
	static double	pre_rot_coeff;

	if (pre_rot_coeff != rot_coeff)
	{
		pre_rot_coeff = rot_coeff;
		fdf->rot_Y[0] = cos(rot_coeff);	
		fdf->rot_Y[2] = sin(rot_coeff);	
		fdf->rot_Y[6] = -fdf->rot_Y[2];	
		fdf->rot_Y[8] = fdf->rot_Y[0];	
	}
}

void	set_rot_mat_Z(t_fdf *fdf, double rot_coeff)
{
	static double	pre_rot_coeff;

	if (pre_rot_coeff != rot_coeff)
	{
		pre_rot_coeff = rot_coeff;
		fdf->rot_Z[0] = cos(rot_coeff);	
		fdf->rot_Z[1] = -sin(rot_coeff);	
		fdf->rot_Z[3] = -fdf->rot_Z[1];	
		fdf->rot_Z[4] = fdf->rot_Z[0];
	}	
}

//void	set_scl_mat(t_fdf * fdf)
//{
//	fdf->scl[0]
//}

int		init_rot_mat(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < 9)
	{
		fdf->rot_X[i] = 0;
		fdf->rot_Y[i] = 0;
		fdf->rot_Z[i] = 0;
		fdf->scl[i] = 0;
	}
	fdf->rot_X[0] = 1;
	set_rot_mat_X(fdf, fdf->rot_coeff);
	fdf->rot_Y[4] = 1;
	set_rot_mat_Y(fdf, fdf->rot_coeff);
	fdf->rot_Z[8] = 1;
	set_rot_mat_Z(fdf, fdf->rot_coeff);
	return (1);
}
