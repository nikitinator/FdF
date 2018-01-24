/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pnts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:58:23 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/24 17:03:46 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mov_x(void *param, double n)
{
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	fdf = (t_fdf *)param;
	j = 0;
	ft_putendl("increase_X_test");
	fdf->pnts.center[X] += n;
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
		{
			fdf->pnts.arr[j][i][X] += n;
			i++;
		}
		j++;
	}
}

void	mov_y(void *param, double n)
{
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	fdf = (t_fdf *)param;
	fdf->pnts.center[Y] += n;
	j = 0;
	ft_putendl("increase_Y_test");
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
		{
			fdf->pnts.arr[j][i][Y] += n;
			i++;
		}
		j++;
	}
}

void	mov_z(void *param, double n)
{
	t_fdf 	*fdf;
	size_t	j;
	size_t	i;

	fdf = (t_fdf *)param;
	fdf->pnts.center[Z] += n;
	j = 0;
	ft_putendl("increase_Z_test");
	while (j < fdf->pnts.row)
	{
		i = 0;
		while (i < fdf->pnts.col)
		{
			fdf->pnts.arr[j][i][Z] += n;
			i++;
		}
		j++;
	}
}

void	transform_pnts(void *param, double x, double y, double z)
{
	if (x)
		mov_x(param, x);
	if (y)
		mov_y(param, y);
	if (z)
		mov_z(param, z);
}