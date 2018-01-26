/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:02:31 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/26 14:25:32 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_red(t_fdf *fdf)
{
	if (fdf->pxls.arr[j][i][PXL_CLR] & 0x00110000 != 0x00FF0000)
		fdf->pxls.arr[j][i][PXL_CLR] += 0x00FF0000;
}

void	add_grn(t_fdf *fdf)
{
	if (fdf->pxls.arr[j][i][PXL_CLR] & 0x001100 != 0x0000FF00)
		fdf->pxls.arr[j][i][PXL_CLR] += 0x00001100;
}

void	add_blu(t_fdf *fdf)
{
	if (fdf->pxls.arr[j][i][PXL_CLR] & 0x0000011 != 0x000000FF)
		fdf->pxls.arr[j][i][PXL_CLR] += 0x00000011;
}
