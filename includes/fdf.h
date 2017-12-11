/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:14:03 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/11 17:58:03 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> //file control
#include <unistd.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"

typedef struct	s_pxl
{
	int			x;
	int			y;
	int			color;
}				t_pxl;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

void	drw_line(void *mlx_ptr, void *win_ptr, t_pxl *pixel1, t_pxl *pixel2);
t_pxl	*pxl_new(int x, int y, int color);

#endif
