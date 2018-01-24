/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:37:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/24 16:57:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(void *param, double rot_coeff)
{
	t_fdf 	*fdf;
	t_point temp;

	fdf = (t_fdf *)param;
	temp[X]= fdf->pnts.center[X];
	temp[Y] = fdf->pnts.center[Y];
	temp[Z] = fdf->pnts.center[Z];

	set_rot_mat_x(fdf, rot_coeff);
	transform_pnts(param, -fdf->pnts.center[X], -fdf->pnts.center[Y],
		   	-fdf->pnts.center[Z]);
	mult_matr(fdf->rot_x, &fdf->pnts);
	transform_pnts(param, temp[X], temp[Y], temp[Z]);
	ft_putendl("rotate_X_test");
}

void	rotate_y(void *param, double rot_coeff)
{
	t_fdf 	*fdf;
	t_point temp;

	fdf = (t_fdf *)param;
	temp[X]= fdf->pnts.center[X];
	temp[Y] = fdf->pnts.center[Y];
	temp[Z] = fdf->pnts.center[Z];

	set_rot_mat_x(fdf, rot_coeff);
	transform_pnts(param, -fdf->pnts.center[X], -fdf->pnts.center[Y],
		   	-fdf->pnts.center[Z]);
	mult_matr(fdf->rot_y, &fdf->pnts);
	transform_pnts(param, temp[X], temp[Y], temp[Z]);
	
	ft_putendl("rotate_Y_test");
}


void	rotate_z(void *param, double rot_coeff)
{
	t_fdf 	*fdf;
	t_point temp;

	fdf = (t_fdf *)param;
	temp[X]= fdf->pnts.center[X];
	temp[Y] = fdf->pnts.center[Y];
	temp[Z] = fdf->pnts.center[Z];

	set_rot_mat_z(fdf, rot_coeff);
	transform_pnts(param, -fdf->pnts.center[X], -fdf->pnts.center[Y],
		   	-fdf->pnts.center[Z]);
	mult_matr(fdf->rot_z, &fdf->pnts);
	transform_pnts(param, temp[X], temp[Y], temp[Z]);
	ft_putendl("rotate_Z_test");
}
