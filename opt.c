/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:27:30 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/23 18:15:47 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	judge_square(t_vars *vars, t_map *map)
{
	if (map->map[vars->ply_y - 1][vars->ply_x - 1] == 'C')
	{
		overwrite_bg(vars, vars->ply_x - 1, vars->ply_y - 1);
		vars->c_cnt --;
		map->map[vars->ply_y - 1][vars->ply_x - 1] = '0';
	}
	if (map->map[vars->ply_y - 1][vars->ply_x - 1] == 'E' && vars->c_cnt == 0)
		exit(EXIT_SUCCESS);
}

void	move_up(t_vars *vars, t_map map)
{
	if (map.map[vars->ply_y - 2][vars->ply_x - 1] == '1')
		return ;
	overwrite_bg(vars, vars->ply_x - 1, vars->ply_y - 1);
	vars->ply_y --;
	judge_square(vars, &map);
	draw_ply(*vars, vars->ply_x, vars->ply_y);
	if (map.map[vars->ply_y][vars->ply_x - 1] == 'E')
		draw_exit(*vars, vars->ply_x, vars->ply_y + 1);
	vars->move_cnt ++;
	ft_putnbr_fd(vars->move_cnt, 1);
	write(1, "\n", 1);
}

void	move_left(t_vars *vars, t_map map)
{
	if (map.map[vars->ply_y - 1][vars->ply_x - 2] == '1')
		return ;
	overwrite_bg(vars, vars->ply_x - 1, vars->ply_y - 1);
	vars->ply_x --;
	judge_square(vars, &map);
	draw_ply(*vars, vars->ply_x, vars->ply_y);
	if (map.map[vars->ply_y - 1][vars->ply_x] == 'E')
		draw_exit(*vars, vars->ply_x + 1, vars->ply_y);
	vars->move_cnt ++;
	ft_putnbr_fd(vars->move_cnt, 1);
	write(1, "\n", 1);
}

void	move_right(t_vars *vars, t_map map)
{
	if (map.map[vars->ply_y - 1][vars->ply_x] == '1')
		return ;
	overwrite_bg(vars, vars->ply_x - 1, vars->ply_y - 1);
	vars->ply_x ++;
	judge_square(vars, &map);
	draw_ply(*vars, vars->ply_x, vars->ply_y);
	if (map.map[vars->ply_y - 1][vars->ply_x - 2] == 'E')
		draw_exit(*vars, vars->ply_x - 1, vars->ply_y);
	vars->move_cnt ++;
	ft_putnbr_fd(vars->move_cnt, 1);
	write(1, "\n", 1);
}

void	move_down(t_vars *vars, t_map map)
{
	if (map.map[vars->ply_y][vars->ply_x - 1] == '1')
		return ;
	overwrite_bg(vars, vars->ply_x - 1, vars->ply_y - 1);
	vars->ply_y ++;
	judge_square(vars, &map);
	draw_ply(*vars, vars->ply_x, vars->ply_y);
	if (map.map[vars->ply_y - 2][vars->ply_x - 1] == 'E')
		draw_exit(*vars, vars->ply_x, vars->ply_y - 1);
	vars->move_cnt ++;
	ft_putnbr_fd(vars->move_cnt, 1);
	write(1, "\n", 1);
}
