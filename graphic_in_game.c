/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_in_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:44:50 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 18:07:47 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	overwrite_bg(t_vars *vars, int x, int y)
{
	int		i;
	int		j;

	i = x * 16;
	while (i < (x + 1) * 16)
	{
		j = y * 16;
		while (j < (y + 1) * 16)
		{
			mlx_pixel_put(vars->mlx, vars->win, i, j, 0x578a3d);
			j ++;
		}
		i++;
	}
}

void	draw_ply(t_vars vars, int x, int y)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(vars.mlx, "./xpm/GCrab.xpm", &w, &h);
	w = (x - 1) * 16;
	h = (y - 1) * 16;
	mlx_put_image_to_window(vars.mlx, vars.win, img, w, h);
	mlx_destroy_image(vars.mlx, img);
}

void	draw_exit(t_vars vars, int x, int y)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(vars.mlx, "./xpm/Portal.xpm", &w, &h);
	w = (x - 1) * 16;
	h = (y - 1) * 16;
	mlx_put_image_to_window(vars.mlx, vars.win, img, w, h);
	mlx_destroy_image(vars.mlx, img);
}
