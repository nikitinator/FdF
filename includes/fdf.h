/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:14:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/19 15:26:17 by snikitin         ###   ########.fr       */
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

#define R 2
#define G 1
#define B 0


# define IMG_WIDTH 1600 
# define IMG_HEIGHT 1200 

# define BUT_8 91
# define BUT_4 86
# define BUT_6 88
# define BUT_2 84
# define BUT_MIN 78
# define BUT_PLU 69
# define BUT_J 38	
# define BUT_K 40	
# define BUT_H 4	
# define BUT_L 37	
# define BUT_MUL 75
# define BUT_DIV 67
# define BUT_SPACE 49
# define BUT_UP 126
# define BUT_DOWN 125
# define BUT_LEFT 123
# define BUT_RIGHT 124
# define BUT_UPLF 115
# define BUT_DWRI 119
# define BUT_C 8

# define ORTOGONAL 0
# define PERSPECTIVE 1

# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define RED 0x00FF0000

# define CHK_PIX(x, y) if((0 < x && x< IMG_WIDTH) && (0 < y && y<IMG_HEIGHT))
# define PUT_PIX(x, y, i, c) *(int *)(i->arr+(x*i->by_pp+i->size_line*y)) = c;
# define SET_PIX(x, y, i, c) CHK_PIX(x, y)PUT_PIX(x, y, i, c)

size_t	g_row;
size_t	g_col;

typedef double t_point[4];
typedef float	t_vec[3];
typedef int t_pixel[3];

typedef float	t_matr3[9];

typedef union	u_color
{
	unsigned int	c_32;
	unsigned char	c_8[3];
}				t_color;

typedef struct	s_drw_ln
{
	int		delta_X;
	int		delta_Y;
	int		sign_X;
	int		sign_Y;
	int		error;
	int		error2;
	float	pix_num;
	float	m[3];
	t_color	c1;
	t_color c2;
}				t_drw_ln;

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
	t_pixel center; //
	t_pixel	**arr;
}				t_pixarr;

typedef struct	s_img
{
	void	*pnt_img;
	int		bi_pp; //bits per pixel
	int		by_pp;
	int		size_line;
	int		endian;	
	char	*arr;
}				t_img;

typedef struct	s_func_key_hook
{
	int		key;
	void	(*f)();
}				t_func_key_hook;

typedef struct			s_fdf
{
	int					fd;
	int					pr_type;
	void				*mlx;
	void				*win;
	t_img				*img;
	t_func_key_hook		func[20];
	t_pntarr			pnts;
	t_pixarr			pxls;
	float				mov_coeff;
	float				scl_coeff;
	float				rot_coeff;	
	t_matr3				rot_X;
	t_matr3				rot_Y;
	t_matr3				rot_Z;
	t_matr3				scl;
	void				(*f[100])(void *param);
}						t_fdf;


int		init_rot_mat(t_fdf *fdf);
void	set_rot_mat_X(t_fdf *fdf, double rot_coeff);
void	set_rot_mat_Y(t_fdf *fdf, double rot_coeff);
void	set_rot_mat_Z(t_fdf *fdf, double rot_coeff);

void	mult_matr(t_matr3 matrix, t_pntarr *pnts);

//void		print_fdf(void *mlx, void *win, t_pixarr *pxarr);
void		print_fdf(void *mlx, void *win, t_img *img, t_pixarr *pxarr);

void		normalize_pnts(t_pntarr *pnts);

void		mult_matr(t_matr3 matrix, t_pntarr *pnts);
void		transform_pnts(void *param, double x, double y, double z);
void		scale_pnts(void *param, double x, double y, double z);
void		mov_X(void *param, double n);
void		mov_Y(void *param, double n);
void		mov_Z(void *param, double n);

void		rotate_X(void *param, double rot_coeff);
void		rotate_Y(void *param, double rot_coeff);
void		rotate_Z(void *param, double rot_coeff);

t_pntarr	*get_point_arr(int fd);
t_pixarr	*get_pixel_arr(t_fdf *fdf);
void		drw_line(void *mlx, void *win, t_pixel pixel1, t_pixel pixel2);
//void		drw_line_bras(void *mlx, void *win, t_pixel pixel1, t_pixel pixel2);
void		drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2);

t_pxl		*pxl_new(int x, int y, int color);

#endif
