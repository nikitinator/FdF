/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:14:03 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/26 14:01:17 by snikitin         ###   ########.fr       */
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
# define PNT_CLR 3

# define PXL_CLR 2

# define IMG_WIDTH 1280
# define IMG_HEIGHT 1027


# define WHITE 0x00FFFFFF

size_t	g_row;
size_t	g_col;

typedef float t_point[4];
typedef float	t_vec[3];
typedef float t_pixel[3];

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

typedef struct	s_pntarr
{
	size_t	col;
	size_t	row;
	t_point	**arr;
}				t_pntarr;

typedef struct	s_pixarr
{
	size_t	col;
	size_t	row;
	t_pixel	**arr;
}				t_pixarr;

void		print_fdf(void *mlx, void *win, t_pixarr *pxarr);

t_pntarr	*get_point_arr(int fd);
t_pixarr	*get_pixel_arr(t_pntarr *arr);
void		drw_line(void *mlx, void *win, t_pixel pixel1, t_pixel pixel2);

t_pxl		*pxl_new(int x, int y, int color);

#endif
