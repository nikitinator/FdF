/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:03:25 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 18:03:17 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	create_grid(t_vec ***grid, char *str)
{
	size_t i;
	size_t j;
	extern size_t g_row;
	extern size_t g_col;

	g_row = ft_countchr(str, '\n') + 1;
	g_col = (ft_countchr(str, ' ')/g_row) + 1;

	*grid = malloc((g_row) * sizeof(t_vec*));
	j = 0;
	while(j < g_row)
	{
		i = 0;
		*grid[j] = malloc((g_col) * sizeof(t_vec));
		while(i < g_col)
		{
			*grid[j][i][X] = i;
			*grid[j][i][Y] = g_row - j;
			*grid[j][i][Z] = ft_atoi(str);
			str = ft_strchr(str, ' ') + 1;

			i++;
		}
		j++;
	}
	return (0);
}

t_vec		***get_point_arr(int fd)
{
	char	*line;
	char	*lines;
	char	**lines_split;
	t_vec	***grid;

	grid = malloc(sizeof(t_vec **));
	if (!(lines = ft_strnew(0)))
		return (NULL);
	while(get_next_line(fd, &line) > 0)	
		lines = ft_strjoin_free(lines, line);
	lines_split = ft_strsplit(lines, '\n');
	free(lines);
	create_grid(grid, lines);
	return (grid);
}
