/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:09 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/05 14:00:51 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void *mlx;
	void *mlx_win;
	int i;
	int j;
	int width = 500;
	int height = 500;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "so_long");
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			mlx_pixel_put(mlx, mlx_win, i, j, 127);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (1);
}
