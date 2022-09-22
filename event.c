/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:27:48 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/22 22:40:52 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event_hooks(t_vars vars)
{
	mlx_hook(vars.win, 2, 1L << 0, key_press_event, &vars);
	mlx_hook(vars.win, 17, 0L, close_win, &vars);
}

int	key_press_event(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_win();
	else if (keycode == 13)
		move_up(vars, vars->map);
	else if (keycode == 0)
		move_left(vars, vars->map);
	else if (keycode == 2)
		move_right(vars, vars->map);
	else if (keycode == 1)
		move_down(vars, vars->map);
	return (0);
}

int	close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
