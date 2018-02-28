/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:35:22 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/28 19:36:44 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_token(char *str)
{
	int		i;
	int		times_comma;
	int		times_x;

	i = 0;
	times_comma = 0;
	times_x = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == '0')
			times_comma++;
		else if ((str[i] == 'x' || str[i] == 'X') && str[i - 2] == ','
				&& ft_isalnum(str[i + 1]))
			times_x++;
		else if (ft_isalnum(str[i]))
			;
		else
			return (-1);
		i++;
	}
	if (times_comma == times_x && times_comma <= 1)
		return (0);
	return (-1);
}

t_list		*validate_list(t_list *list)
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
			if (validate_token(tokens[i]))
				return (del_return(list_copy));
			i++;
		}
		list = list->next;
	}
	return (list_copy);
}
