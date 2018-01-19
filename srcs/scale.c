/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:21:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/19 16:15:21 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	scale_pnts(void	*param, double x, double y, double z)
{	
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;
	t_point temp;

	fdf = (t_fdf *)param;
	ft_putendl("scale_pnts");

	temp[X]= fdf->pnts.center[X];
	temp[Y] = fdf->pnts.center[Y];
	temp[Z] = fdf->pnts.center[Z];
	transform_pnts(param, -fdf->pnts.center[X], -fdf->pnts.center[Y],
		   	-fdf->pnts.center[Z]);
	j = 0;
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
		{
			fdf->pnts.arr[j][i][X] *= x;
			fdf->pnts.arr[j][i][Y] *= y;
			fdf->pnts.arr[j][i][Z] *= z;
			i++;
		}
		j++;
	}
	transform_pnts(param, temp[X], temp[Y], temp[Z]);
}
