/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:31:19 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:02:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_upper_lower(t_pntarr *p, int *upper, int *lower)
{
	size_t	j;
	size_t	i;

	*upper = 0;
	*lower = 0;
	j = 0;
	while (j < fdf->p.row)
	{
		i = 0;
		while (i < fdf->ps.col)
		{
			if (p.arr[j][i][Z] > *upper)
				*upper = p.arr[j][i][Z];
			if (p.arr[j][i][Z] < *lower)
				*upper = p.arr[j][i][Z];
			i++;
		}
		j++;
	}
}
