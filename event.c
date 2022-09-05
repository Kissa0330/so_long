#include "so_long.h"

int	key_press_event(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close(vars);
	return (0);
}

void	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}
