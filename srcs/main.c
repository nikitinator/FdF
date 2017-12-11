/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/08 17:30:34 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"

int		main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	if (!(mlx = mlx_init()))
		return (0);
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 5;
	while (y <350)
	{
		x = 49;
		while (x < 351)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return(0);
}
