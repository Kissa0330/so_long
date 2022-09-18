/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:42:09 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/18 22:49:58 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_vars	vars;
	int		fd;

	(void)argc;
	if (argv[1] == NULL)
		error_output(NULL, NULL, NULL);
	fd = open(argv[1], O_RDONLY);
	map = map_read(fd);
	vars.mlx = mlx_init();
	vars.x = (map.x - 1) * 16;
	vars.y = (map.y - 1) * 16;
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, key_press_event, &vars);
	mlx_hook(vars.win, 17, 0L, close_win, &vars);
	create_bg(vars);
	draw_map(vars, map);
	mlx_loop(vars.mlx);
}
