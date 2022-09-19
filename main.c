/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:09 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 10:57:25 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_map	map;
	t_vars	vars;
	int		fd;

	(void)argc;
	if(path_check(argv[1]) == -1)
		error_output();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_output();
	map = map_read(fd);
	vars.mlx = mlx_init();
	vars.x = (map.x) * 16;
	vars.y = (map.y - 1) * 16;
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "so long ...");
	event_hooks(vars);
	create_bg(vars);
	draw_map(&vars, map);
	mlx_loop(vars.mlx);
}
