/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 19:02:13 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

//major srak

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int		fd;
		void	*mlx;
		void	*win;
		mlx = NULL;

		const int		image_width = IMG_WIDTH;
		const int		image_height = IMG_HEIGHT;

		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			return (-1);
		if (!(mlx = mlx_init()))
			return (-1);
		if (!(win = mlx_new_window(mlx, image_width, image_height, "mlx 42")))
			return (-1);
//		mlx_string_put (mlx, win, 50, 50, WHITE, "JOPA" );
		print_fdf(mlx, win,
				get_pixel_arr(
					*get_point_arr(fd)));
		mlx_loop(mlx);
	}
	ft_putendl_fd("usage: fdf source file", 2);
	return(0);
}
