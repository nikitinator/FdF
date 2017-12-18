/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:59:29 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 14:08:42 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char		*result;

	if (!(result = ft_strjoin(s1, s2)))
		return (NULL);
	free((void *)s1);
	free((void *)s2);
	return (result);
}
