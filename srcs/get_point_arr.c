/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:03:25 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 19:24:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	create_grid(t_vec ***grido, char *str)
{
	size_t i;
	size_t j;
	extern size_t g_row;
	extern size_t g_col;

	t_vec **grid;

	printf("g_row: %zu\n", g_row);
	printf("g_col: %zu\n", g_col);
	grid = malloc((g_row) * sizeof(t_vec*));
	*grido = grid;
	j = 0;
	printf("\n\ncreate grid!\n");
	while(j < g_row)
	{
		i = 0;
		grid[j] = malloc((g_col) * sizeof(t_vec));
		while(i < g_col)
		{
			grid[j][i][X] = i;
			grid[j][i][Y] = g_row - j - 1;
			grid[j][i][Z] = (ft_atoi(str) * -1) - 1.0;
			printf("x: %f, y: %f, z:%f\n",grid[j][i][X], grid[j][i][Y], grid[j][i][Z]);
            while (*str && *str != ' ')
				str++;
            while (*str == ' ')
				str++;
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
	t_vec	***grid;
	extern size_t g_row;
	extern size_t g_col;


	grid = malloc(sizeof(t_vec ***));
	if (!(lines = ft_strnew(0)))
		return (NULL);
	while(get_next_line(fd, &line) > 0)	
	{
		g_row++;
		lines = ft_strjoin_free(lines, line);
	}
	g_col = ((ft_cntwrd(lines) + g_row)/g_row);
	printf("%s\n",lines);
	create_grid(grid, lines);
	return (grid);
}
