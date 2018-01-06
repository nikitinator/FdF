/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:14:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/06 17:11:50 by snikitin         ###   ########.fr       */
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
# define IMG_HEIGHT 1024

# define BUT_8 91
# define BUT_4 86
# define BUT_6 88
# define BUT_2 84
# define BUT_min 78
# define BUT_plu 69

# define WHITE 0x00FFFFFF

size_t	g_row;
size_t	g_col;

typedef double t_point[4];
typedef float	t_vec[3];
typedef double t_pixel[3];

typedef float	MATRIX3[9];

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
	t_point center;
	t_point	**arr;
}				t_pntarr;

typedef struct	s_pixarr
{
	size_t	col;
	size_t	row;
	t_pixel	**arr;
}				t_pixarr;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_pntarr	*pnts;
	t_pixarr	*pxls;
	float		mov_coeff;
	float		scl_coeff;
	float		rot_coeff;	
	MATRIX3		rot_X;
	MATRIX3		rot_Y;
	MATRIX3		rot_Z;
	void		(*f[100])(void *param);
}				t_fdf;

void		print_fdf(void *mlx, void *win, t_pixarr *pxarr);

void		normalize_pnts(t_pntarr *pnts);

void	mov_X(void *param, double n);
void	mov_Y(void *param, double n);
void	mov_Z(void *param, double n);
t_pntarr	*get_point_arr(int fd);
t_pixarr	*get_pixel_arr(t_pntarr *arr);
void		drw_line(void *mlx, void *win, t_pixel pixel1, t_pixel pixel2);

t_pxl		*pxl_new(int x, int y, int color);

#endif
