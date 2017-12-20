/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:28:55 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/18 17:51:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_fdf(void *mlx, void *win, t_pixel ***pixel0)
{
	size_t	i;
	size_t	j;
	extern size_t	g_row;
	extern size_t	g_col;
	t_pixel **pixels;
	pixels = *pixel0;
	j = 0;
	ft_putendl("lubitel§ govvna");

		while (j < g_row) {
			i = 0;
			while (i < g_col) {
				mlx_pixel_put(mlx, win, (int)(pixels[j][i][X]), (int)(pixels[j][i][Y]), WHITE);
				i++;
			}
			j++;
		}
/*

            while (j < g_row)
            {
                i = 0;
                while (i < g_col - 1)
                {
                    drw_line(mlx, win, pixels[j][i], pixels[j][i + 1]);
                    i++;
                }
                j++;
            }



            j = 0;
            while (j < g_row - 1)
            {
                i = 0;
                while (i < g_col)
                {
                    drw_line(mlx, win, pixels[j][i], pixels[j + 1][i]);
                    i++;
                }
                j++;
            }
*/
}
