/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:53:02 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 18:08:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pixel ***get_pixel_arr(t_point ***ver)
{
	t_pixel ***grid;
	extern size_t	g_row;	
	extern size_t	g_col;
	size_t	i;
	size_t	j;
	grid = malloc(sizeof(t_pixel **));
	*grid = malloc((g_row) * sizeof(t_pixel *));
	j = 0;
	while (j < g_row)
	{
		i = 0;
		*grid[j] = malloc((g_col) * sizeof(t_vec));
		while (i < g_col)
		{
			*grid[j][i][X] = *ver[j][i][X] / -*ver[j][i][Z];
			*grid[j][i][Y] = *ver[j][i][Y] / -*ver[j][i][Z];
			*grid[j][i][X] = ((*grid[j][i][X] + 1) / 2) * IMG_WIDTH;
			*grid[j][i][Y] = ((*grid[j][i][Y] + 1) / 2) * IMG_HEIGHT;
        	printf("i:%zu j:%zu x:%f y:%f\n", i, j, *grid[j][i][X], *grid[j][i][Y]); 
			i++;
		}
		j++;
	}
	return (grid);
}
