/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:32:09 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 18:16:02 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

//major srak

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_point Points[10] = {
			{ 1, -1, -5},
			{ 1, -1, -3},
			{ 1,  1, -5},
			{ 1,  1, -3},
			{-1, -1, -5},
			{-1, -1, -3},
			{-1,  1, -5},
			{-1,  1, -3}
	};

	t_pixel Pixels[10] = {
	   { 0, -0} ,
       { 0, -0} ,
	   { 0,  0} ,
	   { 0,  0} ,
	   {-0, -0} ,
       {-0, -0} ,
       {-0,  0} ,
       {-0,  0} ,
       {-0,  0} ,
    };



	if (argc == 2)
	{
		int		fd;
		void	*mlx;
		void	*win;
		
		const int		image_width = 1280;
		const int		image_height = 1024;


		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			return (fd);
		if (!(mlx = mlx_init()))
			return (-1);
		if (!(win = mlx_new_window(mlx, image_width, image_height, "mlx 42")))
			return (-1);


		mlx_string_put (mlx, win, 50, 50, WHITE, "JOPA" );
	for (int i = 0; i < 8; ++i)
	{ 
        // divide the x and y coordinates by the z coordinate to 
        // project the point on the canvas
        float x_proj = Points[i][X] / -Points[i][Z]; 
        float y_proj = Points[i][Y] / -Points[i][Z]; 
        float x_proj_remap = (1 + x_proj) / 2; 
        float y_proj_remap = (1 + y_proj) / 2; 
        float x_proj_pix = x_proj_remap * image_width; 
        float y_proj_pix = y_proj_remap * image_height; 
		Pixels[i][X] = x_proj_pix;
		Pixels[i][Y] = y_proj_pix;
        printf("corner: %d x:%f y:%f\n", i, x_proj_pix, y_proj_pix);
        mlx_pixel_put(mlx, win, x_proj_pix, y_proj_pix, WHITE);
    } 



//		drw_line(mlx, win, &pixel1, &pixel2);

		mlx_loop(mlx);
	}
	ft_putendl_fd("usage: sossee hooy", 2);
	return(0);
}
