/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_Y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:22:25 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/06 17:13:18 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mov_Y(void *param, double n)
{
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	fdf = (t_fdf *)param;
	fdf->pnts->center[Y] += n;
	j = 0;
	ft_putendl("increase_Y_test");
	while (j < fdf->pnts->row)
	{
		i = 0;
		while (i < fdf->pnts->col)
		{
			fdf->pnts->arr[j][i][Y] += n;
			i++;
		}
		j++;
	}
}
