/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:14:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 20:58:20 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define MOV_COEFF 5
# define SCL_COEFF 5
# define XY_COORD_MUL 10

# define X 0
# define Y 1
# define Z 2
# define PNT_CLR 3

# define PXL_CLR 2

# define R 2
# define G 1
# define B 0

# define IMG_WIDTH 1600
# define IMG_HEIGHT 1200

# define HELP_1  "+-------------------------------------------------+"
# define HELP_2  "|                             _____   _ _____     |"
# define HELP_3  "|  ESC - Exit                |  ___|_| |  ___|    |"
# define HELP_4  "|                            | |_ / _` | |_       |"
# define HELP_5  "|  R - Reset color           |  _| (_| |  _|      |"
# define HELP_6  "|                            |_|  \\__,_|_|        |"
# define HELP_7  "|  F1 - Show Help                                 |"
# define HELP_8  "|                                                 |"
# define HELP_9  "|                                                 |"
# define HELP_10 "|  +---------+                     +-----+        |"
# define HELP_11 "|  |    8    |             SCALE - | * / |        |"
# define HELP_12 "|  |         |                     +-----+        |"
# define HELP_13 "|  | 4  5  6 | - MOVE                             |"
# define HELP_14 "|  |         |                                    |"
# define HELP_15 "|  |    2    |                       +---------+  |"
# define HELP_16 "|  +---------+                       |    ^    |  |"
# define HELP_17 "|                          ROTATE  - | <     > |  |"
# define HELP_18 "|    +------+                        |    v    |  |"
# define HELP_19 "|    |Q W E |                        +---------+  |"
# define HELP_20 "|    | A S D| - CHANGE COLOR                      |"
# define HELP_21 "|    +------+                                     |"
# define HELP_22 "|                                                 |"
# define HELP_23 "+-------------------------------------------------+"

# define BUT_8 91
# define BUT_4 86
# define BUT_6 88
# define BUT_2 84
# define BUT_MIN 78
# define BUT_PLU 69
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
# define BUT_BIGG 47
# define BUT_LESS 43
# define BUT_A 0
# define BUT_S 1
# define BUT_D 2
# define BUT_Q 12
# define BUT_W 13
# define BUT_E 14
# define BUT_C 8
# define BUT_ESC 53
# define BUT_R 15
# define BUT_F1 122

# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define RED 0x00FF0000

# define CHK_PIX(x, y) if((0 <= x && x< IMG_WIDTH) && (0 <= y && y<IMG_HEIGHT))
# define PUT_PIX(x, y, i, c) *(int *)(i->arr+(x*i->by_pp+i->size_line*y)) = c
# define SET_PIX(x, y, i, c) CHK_PIX(x, y)PUT_PIX(x, y, i, c)

typedef double		t_point[4];
typedef float		t_vec[3];
typedef int			t_pixel[3];
typedef float		t_matr3[9];

typedef union		u_color
{
	unsigned int	c_32;
	unsigned char	c_8[3];
}					t_color;

typedef struct		s_drw_ln
{
	int				flag;
	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				error;
	int				error_2;
	double			pix_num;
	int				t[2];
	float			c[3];
	float			m[3];
	t_color			c1;
	t_color			c2;
}					t_drw_ln;

typedef struct		s_pntarr
{
	size_t			col;
	size_t			row;
	t_point			center;
	t_point			**arr;
}					t_pntarr;

typedef struct		s_pixarr
{
	size_t			col;
	size_t			row;
	int				pr_type;
	t_pixel			**arr;
}					t_pixarr;

typedef struct		s_img
{
	void			*pnt_img;
	int				bi_pp;
	int				by_pp;
	int				size_line;
	int				endian;
	char			*arr;
}					t_img;

typedef struct		s_fdf
{
	int				fd;
	void			*mlx;
	void			*win;
	t_img			img;
	t_pntarr		pnts;
	t_pixarr		pxls;
	float			mov_coeff;
	float			scl_coeff;
	float			rot_coeff;
	t_matr3			rot_x;
	t_matr3			rot_y;
	t_matr3			rot_z;
	t_matr3			scl;
	int				show_help;
	void			(*f[100])(void *param);
}					t_fdf;

typedef struct		s_func_key_hook
{
	int				key;
	void			(*f)(t_fdf *fdf);
}					t_func_key_hook;

int					init_rot_mat(t_fdf *fdf);
void				set_rot_mat_x(t_fdf *fdf, double rot_coeff);
void				set_rot_mat_y(t_fdf *fdf, double rot_coeff);
void				set_rot_mat_z(t_fdf *fdf, double rot_coeff);
void				mult_matr(t_matr3 matrix, t_pntarr *pnts);
void				normalize_pnts(t_pntarr *pnts);
void				mult_matr(t_matr3 matrix, t_pntarr *pnts);
void				transform_pnts(t_fdf *fdf, double x, double y, double z);
void				scale_pnts(void *param, double x, double y, double z);

t_list				*get_list(int fd, size_t *column_num, size_t *row_num);
void				get_point_arr(int fd, t_pntarr *parr);
void				init_pixel_arr(t_fdf *fdf);
void				get_pixel_arr(t_pntarr *parr, t_pixarr *pixarr);
void				drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2);

void				scale_incr(t_fdf *fdf);
void				scale_decr(t_fdf *fdf);

void				mov_vec_x(t_point (*p), double n);
void				mov_vec_y(t_point (*p), double n);
void				mov_vec_z(t_point (*p), double n);

void				mov_incr_x(t_fdf *fdf);
void				mov_incr_y(t_fdf *fdf);
void				mov_incr_z(t_fdf *fdf);
void				mov_decr_x(t_fdf *fdf);
void				mov_decr_y(t_fdf *fdf);
void				mov_decr_z(t_fdf *fdf);

void				rotate(t_fdf *fdf, int axis, double rot_coeff);
void				rotate_incr_x(t_fdf *fdf);
void				rotate_incr_y(t_fdf *fdf);
void				rotate_incr_z(t_fdf *fdf);
void				rotate_decr_x(t_fdf *fdf);
void				rotate_decr_y(t_fdf *fdf);
void				rotate_decr_z(t_fdf *fdf);

void				change_clr_val(t_pixel *p, int clr, int val);
void				add_red(t_fdf *fdf);
void				add_grn(t_fdf *fdf);
void				add_blu(t_fdf *fdf);
void				sub_red(t_fdf *fdf);
void				sub_grn(t_fdf *fdf);
void				sub_blu(t_fdf *fdf);
void				reset_color(t_fdf *fdf);

void				apply_on_pntarr(t_fdf *fdf, double n,
		void (f)(t_point *, double));
void				apply_on_pxlarr(t_fdf *fdf, int clr, int val,
		void (f)(t_pixel *, int clr, int val));

void				exit_fdf(t_fdf *fdf);
void				scrn_upd(t_fdf *fdf);

#endif
