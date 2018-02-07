/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:49:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:03:38 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*get_list(int fd, size_t *column_num, size_t *row_num)
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
				return (NULL);
			split = ft_strsplit(line, ' ');
			ft_list_push_back(&begin_list, &split, sizeof(char ***));
		}
		(*row_num)++;
		free(line);
	}
	return (begin_list);
}
