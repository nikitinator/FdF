/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:55:15 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/30 19:59:06 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_incr_y(t_fdf *fdf)
{
	rotate(fdf, Y, fdf->rot_coeff);
}

void	rotate_decr_y(t_fdf *fdf)
{
	rotate(fdf, Y, -fdf->rot_coeff);
}
