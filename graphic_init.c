/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:53:32 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/20 16:03:38 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_bg(t_vars vars)
{
	t_data	img;
	int		i;
	int		j;

	img.img = mlx_new_image(vars.mlx, vars.x, vars.y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	i = 0;
	while (i < vars.x)
	{
		j = 0;
		while (j < vars.y)
		{
			my_mlx_pixel_put(&img, i, j, 0x578a3d);
			j ++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
}

static void	draw_elements(t_vars *vars, char map, int i, int j)
{
	void	*img;
	int		w;
	int		h;

	img = NULL;
	if (map == '1')
		img = mlx_xpm_file_to_image(vars->mlx, "./xpm/Cliff.xpm", &w, &h);
	else if (map == 'P')
	{
		vars->ply_x = j + 1;
		vars->ply_y = i + 1;
		img = mlx_xpm_file_to_image(vars->mlx, "./xpm/GCrab.xpm", &w, &h);
	}
	else if (map == 'C')
	{
		vars->c_cnt ++;
		img = mlx_xpm_file_to_image(vars->mlx, "./xpm/Chest.xpm", &w, &h);
	}
	else if (map == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, "./xpm/Portal.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, j * 16, i * 16);
	mlx_destroy_image(vars->mlx, img);
}

void	draw_map(t_vars *vars, t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (map.map[i] != NULL)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.map[i][j] != '0')
				draw_elements(vars, map.map[i][j], i, j);
			j ++;
		}
		i ++;
	}
}
