/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:56:00 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/06 21:13:29 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_incr_z(t_fdf *fdf)
{
	rotate(fdf, Z, fdf->rot_coeff);
}

void	rotate_decr_z(t_fdf *fdf)
{
	rotate(fdf, Z, -fdf->rot_coeff);
}
