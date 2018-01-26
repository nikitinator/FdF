/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:02:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/26 14:26:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	sub_red_vec(t_point *p)
{
	if (p[PXL_CLR] & 0x00110000 != 0x00FF0000)
		p[PXL_CLR] -= 0x00FF0000;
}

void	sub_blu_vec(t_point *p)
{
	if (p[PXL_CLR] & 0x001100 != 0x0000FF00)
		p[PXL_CLR] -= 0x00001100;
}

void	sub_grn_vec(t_point *p)
{
	if (p[PXL_CLR] & 0x0000011 != 0x000000FF)
		p[PXL_CLR] -= 0x00000011;
}

void	sub_red(t_fdf *fdf)
{
	apply_on_pntarr(fdf, sub_red_vec);
}

void	sub_grn(t_fdf *fdf)
{
	apply_on_pntarr(fdf, sub_grn_vec);
}

void	sub_blu(t_fdf *fdf)
{
	apply_on_pntarr(fdf, sub_blu_vec);
}
