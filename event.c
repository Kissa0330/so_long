#include "so_long.h"
#include <stdio.h>
int	key_press_event(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_win(vars);
	return (0);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}
