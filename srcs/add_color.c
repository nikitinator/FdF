/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:02:31 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:02:20 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_red(t_fdf *fdf)
{
	apply_on_pxlarr(fdf, R, 11, change_clr_val);
}

void	add_grn(t_fdf *fdf)
{
	apply_on_pxlarr(fdf, G, 11, change_clr_val);
}

void	add_blu(t_fdf *fdf)
{
	apply_on_pxlarr(fdf, B, 11, change_clr_val);
}
