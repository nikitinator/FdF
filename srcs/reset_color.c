/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:13:55 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/06 13:24:28 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_color(t_fdf *fdf)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
		{
			fdf->pxls.arr[j][i][PXL_CLR] = fdf->pnts.arr[j][i][PNT_CLR];
			i++;
		}
		j++;
	}
}
