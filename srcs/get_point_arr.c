/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:03:25 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/09 11:21:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_point_xyz(t_point *p, int x, int y, int z)
{
	(*p)[X] = x * XY_COORD_MUL;
	(*p)[Y] = y * XY_COORD_MUL;
	(*p)[Z] = z;
}

static void		set_point_clr(t_point *p, char *token)
{
	char *color;

	if (((color = ft_strchr(token, ','))) && ft_strnequ(",0x", color, 3))
		(*p)[PNT_CLR] = (float)ft_atoi_base(color + 3, 16);
	else
		(*p)[PNT_CLR] = (float)WHITE;
}

static int		set_arr(t_pntarr *parr, t_list *begin_list)
{
	size_t	i;
	size_t	j;
	char	**tokens;

	j = 0;
	if (!(parr->arr = malloc(parr->row * sizeof(t_point *))))
		return (-1);
	while (begin_list)
	{
		tokens = *(char ***)begin_list->content;
		if (!(parr->arr[j] = malloc(parr->col * sizeof(t_point))))
			return (-1);
		i = 0;
		while (tokens[i])
		{
			set_point_xyz(&parr->arr[j][i], i, j, -ft_atoi(tokens[i]));
			set_point_clr(&parr->arr[j][i], tokens[i]);
			free(tokens[i]);
			i++;
		}
		free(tokens);
		begin_list = begin_list->next;
		j++;
	}
	return (0);
}

static void		del(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
}

void			get_point_arr(int fd, t_pntarr *parr, t_fdf *fdf)
{
	t_list *begin_list;
	t_list *temp;

	if (!(begin_list = get_list(fd, &parr->col, &parr->row)))
	{
		ft_putendl_fd("Invalid input file", 2);
		exit_fdf(fdf);
	}
	temp = begin_list;
	if ((set_arr(parr, begin_list)))
	{
		ft_lstdel(&temp, del);
		exit_fdf(fdf);
	}
	ft_lstdel(&temp, del);
	parr->center[X] = (parr->col - 1) * XY_COORD_MUL / 2.0;
	parr->center[Y] = (parr->row - 1) * XY_COORD_MUL / 2.0;
	parr->center[Z] = 0;
	return ;
}
