/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:03:25 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/05 19:43:34 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_list	*get_list(int fd)
{
	t_list *begin_list;
	char	*line;

	begin_list = NULL;
	while(get_next_line(fd, &line) > 0)	
	{
		if (*line)
		{
			char **split;
			ft_putendl(line);
			split = ft_strsplit(line,' ');

			int k;
			for (int i = 0; split[i]; i++)
			{
				k = i;
			}
			ft_list_push_back(&begin_list, &split, sizeof(char ***));
		}
		free(line);
	}
	return (begin_list);
}

static void		set_arr(t_pntarr *parr, t_list *begin_list)
{
	size_t	i;
	size_t	j;
	char	**tokens;

	tokens = *(char ***)begin_list->content;
	j = 0;
	while (tokens[parr->col])
		parr->col++;

	parr->arr = malloc(parr->row * sizeof(t_point *));
	while(begin_list)
	{
		tokens = *(char ***)begin_list->content;
		parr->arr[j] = malloc(parr->col * sizeof(t_point));
		i = 0;
		while(tokens[i])
		{

            printf("%s\t%d\n",tokens[i] ,ft_atoi(tokens[i]));

			parr->arr[j][i][X] = i;
			parr->arr[j][i][Y] = j;
			parr->arr[j][i][Z] = -(ft_atoi(tokens[i])/3) - 1;
			parr->arr[j][i][PNT_CLR] = (float)WHITE;


			ft_strclr(tokens[i]);
			free(tokens[i]);
			i++;
		}
		free(tokens);
		free(begin_list);
		begin_list = begin_list->next;
		j++;
	}

}

t_pntarr		*get_point_arr(int fd)
{
	t_list *begin_list;
	t_pntarr *parr;
	t_list *temp;

	begin_list = get_list(fd);
	temp = begin_list;

	parr = malloc(sizeof(t_pntarr));
	parr->row = ft_list_count(begin_list);
	parr->col = 0;
	set_arr(parr, begin_list);
	parr->center[X] = (parr->col-1) / 2.0;
	parr->center[Y] = (parr->row-1) / 2.0;
	parr->center[Z] = -1;//

	printf("row: %zu \t col %zu\n", parr->row, parr->col);
	return (parr);
}
