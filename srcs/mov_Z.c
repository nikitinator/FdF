/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_Z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:23:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/06 17:13:50 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mov_Z(void *param, double n)
{
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	fdf = (t_fdf *)param;
	fdf->pnts->center[Z] += n;
	j = 0;
	ft_putendl("increase_Z_test");
	while (j < fdf->pnts->row)
	{
		i = 0;
		while (i < fdf->pnts->col)
		{
			fdf->pnts->arr[j][i][Z] += n;
			i++;
		}
		j++;
	}
}
