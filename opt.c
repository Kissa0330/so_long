/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:27:30 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 18:53:12 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
void move_up(t_vars *vars, t_map map)
{
	printf("%d\n", vars->ply_x);
	printf("%d\n", vars->ply_y);
	if (vars->ply_y == 1)
	{
		printf("test\n");
		return ;
	}
	overwrite_bg(vars, vars->ply_x - 1, vars->ply_y - 1);
	vars->ply_y --;
	printf("%d\n", vars->ply_y);
	if (map.map[vars->ply_y][vars->ply_x] == 'C')
		overwrite_bg(vars, vars->ply_x, vars->ply_y);
}