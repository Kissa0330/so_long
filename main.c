/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:09 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 14:22:51 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		fd;

	(void)argc;
	if(path_check(argv[1]) == -1)
		error_output();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_output();
	vars.map = map_read(fd);
	vars.mlx = mlx_init();
	vars.x = (vars.map.x) * 16;
	vars.y = (vars.map.y - 1) * 16;
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "so long ...");
	event_hooks(vars);
	create_bg(vars);
	draw_map(&vars, vars.map);
	mlx_loop(vars.mlx);
}
