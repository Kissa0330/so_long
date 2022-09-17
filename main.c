/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:09 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/17 18:58:57 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.x = 800;
	vars.y = 800;
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, key_press_event, &vars);
	mlx_hook(vars.win, 17, 0L, close_win, &vars);
	img.img = mlx_new_image(vars.mlx, vars.x, vars.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0xFF00FF);
		}
		
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
