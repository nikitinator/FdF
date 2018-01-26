/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:14:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/01/26 16:03:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define MOV_COEFF 5
# define SCL3_COEFF 5
# define MOV_COEFF 5

# define X 0
# define Y 1
# define Z 2
# define PNT_CLR 3
# define ISTOP 4

# define PXL_CLR 2

# define R 2
# define G 1
# define B 0

# define IMG_WIDTH 1600
# define IMG_HEIGHT 1200

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


# define ORTOGONAL 0
# define PERSPECTIVE 1

# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define RED 0x00FF0000

# define CHK_PIX(x, y) if((0 <= x && x< IMG_WIDTH) && (0 <= y && y<IMG_HEIGHT))
# define PUT_PIX(x, y, i, c) *(int *)(i->arr+(x*i->by_pp+i->size_line*y)) = c
# define SET_PIX(x, y, i, c) CHK_PIX(x, y)PUT_PIX(x, y, i, c)

typedef double	t_point[5];
typedef float	t_vec[3];
typedef int		t_pixel[3];
typedef float	t_matr3[9];

typedef union	u_color
{
	unsigned int	c_32;
	unsigned char	c_8[3];
}				t_color;

typedef struct	s_drw_ln
{
	int		flag;
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	int		error;
	int		error_2;
	double	pix_num;
	int		t[2];
	float	c[3];
	float	m[3];
	t_color	c1;
	t_color c2;
}				t_drw_ln;

typedef struct	s_pntarr
{
	size_t	col;
	size_t	row;
	t_point center;
	t_point	**arr;
	t_list	*z_list;
}				t_pntarr;

typedef struct	s_pixarr
{
	size_t	col;
	size_t	row;
	int		pr_type;
	t_pixel	**arr;
}				t_pixarr;

typedef struct	s_img
{
	void	*pnt_img;
	int		bi_pp;
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

//t_func_key_hook	func[20] = {
//	BUT_8,  
//	BUT_4, 
//	BUT_6,
//	BUT_2,
//	BUT_MIN 78
//	BUT_PLU 69
//	BUT_J 38
//	BUT_K 40
//	BUT_H 4
//	BUT_L 37
//	BUT_MUL 75
//	BUT_DIV 67
//	BUT_SPACE 49
//	BUT_UP 126
//	BUT_DOWN 125
//	BUT_LEFT 123
//	BUT_RIGHT 124
//	BUT_UPLF 115
//	BUT_DWRI 119
//	BUT_C 8
//	BUT_BIGG 47
//	BUT_LESS 43
//}

typedef struct			s_fdf
{
	int					fd;
	int					pr_type;
	void				*mlx;
	void				*win;
	t_img				*img;
	t_pntarr			pnts;
	t_pixarr			pxls;
	float				mov_coeff;
	float				scl_coeff;
	float				rot_coeff;
	t_matr3				rot_x;
	t_matr3				rot_y;
	t_matr3				rot_z;
	t_matr3				scl;
	void				(*f[100])(void *param);
}						t_fdf;


int			init_rot_mat(t_fdf *fdf);
void		set_rot_mat_x(t_fdf *fdf, double rot_coeff);
void		set_rot_mat_y(t_fdf *fdf, double rot_coeff);
void		set_rot_mat_z(t_fdf *fdf, double rot_coeff);
void		mult_matr(t_matr3 matrix, t_pntarr *pnts);
void		print_fdf(void *mlx, void *win, t_img *img, t_pixarr *pxarr);
void		normalize_pnts(t_pntarr *pnts);
void		mult_matr(t_matr3 matrix, t_pntarr *pnts);
void		transform_pnts(void *param, double x, double y, double z);
void		scale_pnts(void *param, double x, double y, double z);
void		mov_x(void *param, double n);
void		mov_y(void *param, double n);
void		mov_z(void *param, double n);
void		rotate_x(void *param, double rot_coeff);
void		rotate_y(void *param, double rot_coeff);
void		rotate_z(void *param, double rot_coeff);
void		get_point_arr(int fd, t_pntarr *parr);
void		init_pixel_arr(t_fdf *fdf);
void		get_pixel_arr(t_pntarr *parr, t_pixarr *pixarr);
void		drw_line_bras(t_img *img, t_pixel pixel1, t_pixel pixel2);

void		scale_inc(void *param);
void		scale_dec(void *param);

void		mov_x_inc(void *param);
void		mov_y_inc(void *param);
void		mov_z_inc(void *param);
void		mov_x_dec(void *param);
void		mov_y_dec(void *param);
void		mov_z_dec(void *param);


void		rotate_x_inc(void *param);
void		rotate_y_inc(void *param);
void		rotate_z_inc(void *param);
void		rotate_x_dec(void *param);
void		rotate_y_dec(void *param);
void		rotate_z_dec(void *param);


void		add_red(t_fdf *fdf);
void		add_grn(t_fdf *fdf);
void		add_blu(t_fdf *fdf);
void		sub_red(t_fdf *fdf);
void		sub_grn(t_fdf *fdf);
void		sub_blu(t_fdf *fdf);

void		apply_on_pntarr(t_fdf *fdf, void (f)(t_point *));
void		apply_on_pixarr(t_fdf *fdf, void (f)(t_point *));


#endif
