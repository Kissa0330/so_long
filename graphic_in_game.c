/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_in_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:44:50 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 18:46:19 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void overwrite_bg(t_vars *vars, int x, int y)
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