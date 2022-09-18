/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:53:32 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/18 22:52:40 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
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

void	draw_map(t_vars vars, t_map map)
{
	int		i;
	int		j;
	void	*image;
	int		w;
	int		h;

	i = 0;
	while (map.map[i] != NULL)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.map[i][j] == '0')
			{
				j ++;
				continue;
			}
			if (map.map[i][j] == '1')
				image = mlx_xpm_file_to_image(vars.mlx, "./xpm/Cliff.xpm", &w, &h);
			else if (map.map[i][j] == 'P')
				image = mlx_xpm_file_to_image(vars.mlx, "./xpm/GCrab.xpm", &w, &h);
			else if (map.map[i][j] == 'C')
				image = mlx_xpm_file_to_image(vars.mlx, "./xpm/Chest.xpm", &w, &h);
			else if (map.map[i][j] == 'E')
				image = mlx_xpm_file_to_image(vars.mlx, "./xpm/Portal.xpm", &w, &h);
			mlx_put_image_to_window(vars.mlx, vars.win, image, j * 16, i * 16);
			j ++;
		}
		i ++;
	}
	
}