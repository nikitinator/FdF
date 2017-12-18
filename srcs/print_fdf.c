/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:28:55 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 17:51:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_fdf(void *mlx, void *win, t_pixel ***pixels)
{
	size_t	i;
	size_t	j;
	extern size_t	g_row;
	extern size_t	g_col;

	j = 0;
	while (j < g_row)
	{
		i = 0;
		while (i < g_col - 1)
		{
			drw_line(mlx, win, *pixels[j][i], *pixels[j][i + 1]);
			i++;
		}
		j++;
	}

	j = 0;
	while (j < g_row - 1)
	{	
		i = 0;
		while (i < g_col)
		{	
			drw_line(mlx, win, *pixels[j][i], *pixels[j + 1][i]);
			i++;
		}
		j++;
	}
}
