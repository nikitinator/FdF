/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/28 15:47:37 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	toggle_show_help(t_fdf *fdf)
{
	fdf->show_help = !fdf->show_help;
}

int		handle_key(int keycode, t_fdf *fdf)
{
	int						i;
	static t_func_key_hook	func[NUM_OF_KEYS] = {
		{BUT_8, mov_decr_y}, {BUT_4, mov_decr_x},
		{BUT_6, mov_incr_x}, {BUT_2, mov_incr_y},
		{BUT_MIN, mov_decr_z}, {BUT_PLU, mov_incr_z},
		{BUT_MUL, scale_decr}, {BUT_DIV, scale_incr},
		{BUT_UP, rotate_decr_x}, {BUT_DOWN, rotate_incr_x},
		{BUT_LEFT, rotate_incr_y}, {BUT_RIGHT, rotate_decr_y},
		{BUT_UPLF, rotate_decr_z}, {BUT_DWRI, rotate_incr_z},
		{BUT_A, sub_red}, {BUT_S, sub_grn}, {BUT_D, sub_blu},
		{BUT_Q, add_red}, {BUT_W, add_grn}, {BUT_E, add_blu},
		{BUT_ESC, exit_fdf}, {BUT_R, reset_color},
		{BUT_F1, toggle_show_help}
		};

	i = 0;
	while (i < NUM_OF_KEYS && func[i].key != keycode)
		i++;
	if (i < NUM_OF_KEYS)
		func[i].f(fdf);
	get_pixel_arr(&fdf->pnts, &fdf->pxls);
	scrn_upd(fdf);
	return (0);
}

void	init_fdf_img(t_img *img, void *mlx_ptr)
{
	img->pnt_img = mlx_new_image(mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img->arr =
		mlx_get_data_addr(img->pnt_img, &img->bi_pp,
				&img->size_line, &img->endian);
	img->by_pp = img->bi_pp / 8;
}

void	init_fdf(t_fdf *fdf)
{
	init_fdf_img(&fdf->img, fdf->mlx);
	get_point_arr(fdf->fd, &(fdf->pnts), fdf);
	transform_pnts(fdf, -fdf->pnts.center[X], -fdf->pnts.center[Y], 0);
	transform_pnts(fdf, IMG_WIDTH / 2.0, IMG_HEIGHT / 2.0, 0);
	init_pixel_arr(fdf);
	fdf->mov_coeff = 5;
	fdf->rot_coeff = M_PI / 180 * 4;
	fdf->scl_coeff = 1.5;
	init_rot_mat(fdf);
	fdf->show_help = 0;
}

int		main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		if ((fdf.fd = open(argv[1], O_RDONLY)) <= 0)
			return (-1);
		if (!(fdf.mlx = mlx_init()))
			return (-1);
		if (!(fdf.win = mlx_new_window(fdf.mlx,
						IMG_WIDTH, IMG_HEIGHT, "mlx 42")))
			return (-1);
		init_fdf(&fdf);
		scrn_upd(&fdf);
		mlx_hook(fdf.win, 2, 5, handle_key, &fdf);
		mlx_hook(fdf.win, 17, 5, (int (*)(void *))exit_fdf, &fdf);
		mlx_loop(fdf.mlx);
	}
	ft_putendl_fd("Usage : ./fdf <filename>", 2);
	return (0);
}
