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
	t_point Points[10] = {
	     { 0, 0, 0}, 
        { 0, 3, 0}, 
	       { 3,  3, 0}, 
	       { 2,  3, 0}, 
	       {0, 3, 0}, 
	        {3, 0, 0}, 
        {3,  3, 3}, 
         {0,  0, 0} , 
        {3,  0, 0}, 
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
    };§:q



	if (argc == 2)
	{
		int		fd;
		void	*mlx;
		void	*win;
		
		const int		image_width = 1280;
		const int		image_height = 1024;


		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			return (fd);	
		t_pxl	pixel1;
		t_pxl	pixel2;
		if (!(mlx = mlx_init()))
			return (-1);
		if (!(win = mlx_new_window(mlx, image_width, image_height, "mlx 42")))
			return (-1);	
		pixel1.x = 80;
		pixel1.y = 40;
		pixel1.color = 0x00FFFFFF;
		
		pixel2.x = 13;
		pixel2.y = 20;
		pixel2.color = 0x00FFFFFF;


	for (int i = 0; i < 10; ++i) 
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
    } 

	for (int i = 0; i < 10; ++i) 
	{
		drw_line(mlx, win, Pixels[i], Pixels[i + 1]); 
	}

//		drw_line(mlx, win, &pixel1, &pixel2);

		mlx_loop(mlx);
	}
	ft_putendl_fd("usage: sossee hooy", 2);
	return(0);
}
