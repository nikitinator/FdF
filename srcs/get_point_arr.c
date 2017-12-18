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

static int	create_grid(t_vec ***grid, char *str)
{
	size_t i;
	size_t j;
	extern size_t g_row;
	extern size_t g_col;

	printf("g_row: %zu\n", g_row);
	printf("g_col: %zu\n", g_col);
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
	t_vec	***grid;
	extern size_t g_row;
	extern size_t g_col;


	grid = malloc(sizeof(t_vec **));
	if (!(lines = ft_strnew(0)))
		return (NULL);
	while(get_next_line(fd, &line) > 0)	
	{
		g_row++;
		lines = ft_strjoin_free(lines, line);
	}
	printf("ft_countchr: %zu\n", ft_countchr(lines, ' '));
	g_col = ((ft_countchr(lines, ' ') + g_row)/g_row);
	printf("%s\n",lines);
	create_grid(grid, lines);
	return (grid);
}
