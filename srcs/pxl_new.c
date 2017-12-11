/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:04:57 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/11 17:46:12 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pxl	*pxl_new(int x, int y, int color)
{
	t_pxl	*pxl_new;
	if (!(pxl_new = (t_pxl *)malloc(sizeof(t_pxl))))
		return (NULL);
	pxl_new->color = color;
	pxl_new->x = x;
	pxl_new->y = y;
	return (pxl_new);
}
