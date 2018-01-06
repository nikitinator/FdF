/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_X.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:20:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/06 17:12:54 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mov_X(void *param, double n)
{
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	fdf = (t_fdf *)param;
	j = 0;
	ft_putendl("increase_X_test");
	fdf->pnts->center[X] += n;
	while (j < fdf->pnts->row)
	{
		i = 0;
		while (i < fdf->pnts->col)
		{
			fdf->pnts->arr[j][i][X] += n;
			i++;
		}
		j++;
	}
}
