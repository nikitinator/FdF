/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/11 17:30:59 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//major srak

int		main(void)
{
	void	*mlx;
	void	*win;
//	int		x;
//	int		y;
	
	t_pxl	pixel1;
	t_pxl	pixel2;
	if (!(mlx = mlx_init()))
		return (0);
	win = mlx_new_window(mlx, 1280, 1024, "mlx 42");
	
	pixel1.x = 80;
	pixel1.y = 40;
	pixel1.color = 0x00FFFFFF;
	
	pixel2.x = 13;
	pixel2.y = 20;
	pixel2.color = 0x00FFFFFF;

	drw_line(mlx, win, &pixel1, &pixel2);
/*	y = 50;
	while (y <350)
	{
		x = 50;
		while (x < 350)
		{
			if(x % 2 && y % 2)
				mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}*/
	mlx_loop(mlx);
	return(0);
}
