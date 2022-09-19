/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:27:48 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 04:03:13 by takanoraika      ###   ########.fr       */
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
		close_win(vars);
	return (0);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}
