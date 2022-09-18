/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:09 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/18 16:36:44 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	create_bg(t_vars vars)
{
	t_data	img;

	img.img = mlx_new_image(vars.mlx, vars.x, vars.y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	for (int i = 0; i < vars.x; i++)
	{
		for (int j = 0; j < vars.y; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0x578a3d);
		}
		
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_vars	vars;
	void	*image;
	int		img_width;
	int		img_height;
	int		fd;

	if (argv[1] == NULL)
		error_output(NULL, NULL, NULL);
	fd = open(argv[1], O_RDONLY);
	map = map_read(fd);
	vars.mlx = mlx_init();
	image = mlx_xpm_file_to_image(vars.mlx, "./Cliff.xpm", &img_width, &img_height);
	vars.x = map.x * 16;
	vars.y = map.y * 16;
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, key_press_event, &vars);
	mlx_hook(vars.win, 17, 0L, close_win, &vars);
	create_bg(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, image, 0, 0);
	mlx_loop(vars.mlx);
}
