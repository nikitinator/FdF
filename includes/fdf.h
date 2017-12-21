/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:14:03 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/21 17:07:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> //file control
# include <unistd.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define X 0
# define Y 1
# define Z 2

# define IMG_WIDTH 1280
# define IMG_HEIGHT 1027

# define WHITE 0x00FFFFFF

size_t	g_row;
size_t	g_col;

typedef struct	s_pxl
{
	int			x;
	int			y;
	int			color;
}				t_pxl;

typedef struct s_ver
{
	float	x;
	float	y;
	float	z;
}				t_ver;

typedef float t_point[3];
typedef float	t_vec[3];
typedef float t_pixel[2];

void	print_fdf(void *mlx, void *win, t_pixel ***pixels);
t_pixel	***get_pixel_arr(t_point **ver);
t_vec	***get_point_arr(int fd);
void	drw_line(void *mlx, void *win, t_pixel pixel1, t_pixel pixel2);

t_pxl	*pxl_new(int x, int y, int color);

#endif
