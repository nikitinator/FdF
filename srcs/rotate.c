/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:37:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/11 19:05:40 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_X(void *param)
{
	t_fdf 	*fdf;
	t_point temp;

	fdf = (t_fdf *)param;
	temp[X]= fdf->pnts->center[X];
	temp[Y] = fdf->pnts->center[Y];
	temp[Z] = fdf->pnts->center[Z];

	transform_pnts(param, -fdf->pnts->center[X], -fdf->pnts->center[Y],
		   	-fdf->pnts->center[Z]);
	mult_matr(fdf->rot_X, fdf->pnts);
	transform_pnts(param, temp[X], temp[Y], temp[Z]);
	ft_putendl("rotate_X_test");
}

void	rotate_Y(void *param)
{
	t_fdf 	*fdf;
	t_point temp;

	fdf = (t_fdf *)param;
	temp[X]= fdf->pnts->center[X];
	temp[Y] = fdf->pnts->center[Y];
	temp[Z] = fdf->pnts->center[Z];

	transform_pnts(param, -fdf->pnts->center[X], -fdf->pnts->center[Y],
		   	-fdf->pnts->center[Z]);
	mult_matr(fdf->rot_Y, fdf->pnts);
	transform_pnts(param, temp[X], temp[Y], temp[Z]);
	
	ft_putendl("rotate_Y_test");
}


void	rotate_Z(void *param)
{
	t_fdf 	*fdf;
	t_point temp;

	fdf = (t_fdf *)param;
	temp[X]= fdf->pnts->center[X];
	temp[Y] = fdf->pnts->center[Y];
	temp[Z] = fdf->pnts->center[Z];

	transform_pnts(param, -fdf->pnts->center[X], -fdf->pnts->center[Y],
		   	-fdf->pnts->center[Z]);
	mult_matr(fdf->rot_Z, fdf->pnts);
	transform_pnts(param, temp[X], temp[Y], temp[Z]);
	ft_putendl("rotate_Z_test");
}
