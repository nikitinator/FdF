/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_upd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:43:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/02/07 21:06:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_fdf(void *mlx, void *win, t_img *img, t_pixarr *p)
{
	size_t	i;
	size_t	j;

	ft_bzero(img->arr, IMG_HEIGHT * img->size_line);
	j = 0;
	while (j < p->row - 1)
	{
		i = 0;
		while (i < p->col - 1)
		{
			drw_line_bras(img, p->arr[j][i], p->arr[j][i + 1]);
			drw_line_bras(img, p->arr[j][i], p->arr[j + 1][i]);
			i++;
		}
		drw_line_bras(img, p->arr[j][i], p->arr[j + 1][i]);
		j++;
	}
	i = 0;
	while (i < p->col - 1)
	{
		drw_line_bras(img, p->arr[j][i], p->arr[j][i + 1]);
		i++;
	}
	SET_PIX(p->arr[j][i][X], p->arr[j][i][Y], img, p->arr[j][i][PXL_CLR]);
	mlx_put_image_to_window(mlx, win, img->pnt_img, 0, 0);
}

static void	print_help(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 5, 20, WHITE, HELP_1);
	mlx_string_put(fdf->mlx, fdf->win, 5, 35, WHITE, HELP_2);
	mlx_string_put(fdf->mlx, fdf->win, 5, 50, WHITE, HELP_3);
	mlx_string_put(fdf->mlx, fdf->win, 5, 65, WHITE, HELP_4);
	mlx_string_put(fdf->mlx, fdf->win, 5, 80, WHITE, HELP_5);
	mlx_string_put(fdf->mlx, fdf->win, 5, 95, WHITE, HELP_6);
	mlx_string_put(fdf->mlx, fdf->win, 5, 110, WHITE, HELP_7);
	mlx_string_put(fdf->mlx, fdf->win, 5, 125, WHITE, HELP_8);
	mlx_string_put(fdf->mlx, fdf->win, 5, 140, WHITE, HELP_9);
	mlx_string_put(fdf->mlx, fdf->win, 5, 155, WHITE, HELP_10);
	mlx_string_put(fdf->mlx, fdf->win, 5, 170, WHITE, HELP_11);
	mlx_string_put(fdf->mlx, fdf->win, 5, 185, WHITE, HELP_12);
	mlx_string_put(fdf->mlx, fdf->win, 5, 200, WHITE, HELP_13);
	mlx_string_put(fdf->mlx, fdf->win, 5, 215, WHITE, HELP_14);
	mlx_string_put(fdf->mlx, fdf->win, 5, 230, WHITE, HELP_15);
	mlx_string_put(fdf->mlx, fdf->win, 5, 245, WHITE, HELP_16);
	mlx_string_put(fdf->mlx, fdf->win, 5, 260, WHITE, HELP_17);
	mlx_string_put(fdf->mlx, fdf->win, 5, 275, WHITE, HELP_18);
	mlx_string_put(fdf->mlx, fdf->win, 5, 290, WHITE, HELP_19);
	mlx_string_put(fdf->mlx, fdf->win, 5, 305, WHITE, HELP_20);
	mlx_string_put(fdf->mlx, fdf->win, 5, 320, WHITE, HELP_21);
	mlx_string_put(fdf->mlx, fdf->win, 5, 335, WHITE, HELP_22);
	mlx_string_put(fdf->mlx, fdf->win, 5, 350, WHITE, HELP_23);
}

void		scrn_upd(t_fdf *fdf)
{
	print_fdf(fdf->mlx, fdf->win, &fdf->img, &fdf->pxls);
	mlx_string_put(fdf->mlx, fdf->win, 15, 0, WHITE, "F1 - HELP");
	if (fdf->show_help)
		print_help(fdf);
}
