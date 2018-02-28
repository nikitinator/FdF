/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:49:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/28 19:37:53 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		del_content(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

void		list_free(t_list *list)
{
	char	**tokens;
	t_list	*list_copy;
	int		i;

	list_copy = list;
	while (list)
	{
		tokens = *(char ***)list->content;
		i = 0;
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
		list = list->next;
	}
	if (list_copy)
		ft_lstdel(&list_copy, del_content);
}

static void	*del_return(t_list *list)
{
	ft_putendl_fd("Invalid argument", 2);
	list_free(list);
	return (NULL);
}

t_list		*get_list(int fd, size_t *column_num, size_t *row_num)
{
	char	*line;
	char	**split;
	t_list	*begin_list;

	*column_num = 0;
	*row_num = 0;
	begin_list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line)
		{
			if (*column_num == 0)
				*column_num = ft_cntwrd(line);
			else if (*column_num != ft_cntwrd(line))
			{
				free(line);
				return (del_return(begin_list));
			}
			split = ft_strsplit(line, ' ');
			ft_list_push_back(&begin_list, &split, sizeof(char ***));
		}
		(*row_num)++;
		free(line);
	}
	return (validate_list(begin_list));
}
