/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:38:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:04:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mult_matr(t_matr3 matrix, t_pntarr *pnts)
{
	size_t	i;
	size_t	j;
	double	temp[3];

	j = 0;
	while (j < pnts->row)
	{
		i = 0;
		while (i < pnts->col)
		{
			temp[X] = matrix[0] * pnts->arr[j][i][X] +
				matrix[1] * pnts->arr[j][i][Y] + matrix[2] * pnts->arr[j][i][Z];
			temp[Y] = matrix[3] * pnts->arr[j][i][X] +
				matrix[4] * pnts->arr[j][i][Y] + matrix[5] * pnts->arr[j][i][Z];
			temp[Z] = matrix[6] * pnts->arr[j][i][X] +
				matrix[7] * pnts->arr[j][i][Y] + matrix[8] * pnts->arr[j][i][Z];
			pnts->arr[j][i][X] = temp[X];
			pnts->arr[j][i][Y] = temp[Y];
			pnts->arr[j][i][Z] = temp[Z];
			i++;
		}
		j++;
	}
}
