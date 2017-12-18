/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:07:30 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 15:15:37 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	ft_strchr_count counts the number of occurences of char k in string str
*/
 
size_t	ft_countchr(char *str, char k)
{
	size_t	n;

	if (!str)
		return (0);
	n = 0;
	while(*str)
		if(*str++ == k)
			n++;
	return (n);
}
