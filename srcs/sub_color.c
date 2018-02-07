/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:02:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:05:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sub_red(t_fdf *fdf)
{
	apply_on_pxlarr(fdf, R, -11, change_clr_val);
}

void	sub_grn(t_fdf *fdf)
{
	apply_on_pxlarr(fdf, G, -11, change_clr_val);
}

void	sub_blu(t_fdf *fdf)
{
	apply_on_pxlarr(fdf, B, -11, change_clr_val);
}
