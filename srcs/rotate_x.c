/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:54:39 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/30 19:54:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_incr_x(t_fdf *fdf)
{
	rotate(fdf, X, fdf->rot_coeff);
}

void	rotate_decr_x(t_fdf *fdf)
{
	rotate(fdf, X, -fdf->rot_coeff);
}
