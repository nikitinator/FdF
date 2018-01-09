/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:21:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/09 16:41:02 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	scale_pnts(void	*param, double x, double y, double z)
{	
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	fdf = (t_fdf *)param;
	j = 0;
	ft_putendl("scale_pnts");
	fdf->pnts->center[X] *= x;
	fdf->pnts->center[Y] *= y;
	fdf->pnts->center[Z] *= z;
	while (j < fdf->pnts->row)
	{
		i = 0;
		while (i < fdf->pnts->col)
		{
			fdf->pnts->arr[j][i][X] *= x;
			fdf->pnts->arr[j][i][Y] *= y;
			fdf->pnts->arr[j][i][Z] *= z;
			i++;
		}
		j++;
	}
}
