/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:09 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/20 17:57:25 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	vars_init(t_vars *vars, char *path)
{
	int	fd;

	if (path_check(path) == -1)
		error_output();
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_output();
	vars->map = map_read(fd);
	vars->mlx = mlx_init();
	vars->x = (vars->map.x) * 16;
	vars->y = (vars->map.y - 1) * 16;
	vars->c_cnt = 0;
	vars->move_cnt = 0;
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, "so long ...");
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		error_output();
	vars_init(&vars, argv[1]);
	create_bg(vars);
	draw_map(&vars, vars.map);
	event_hooks(vars);
	mlx_loop(vars.mlx);
}
