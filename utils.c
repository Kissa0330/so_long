/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:24:50 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/18 16:52:02 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_structs(t_map *map, t_vars *var, t_data *data)
{
	int	i;

	if (data != NULL)
	{
		if ((*data).img != NULL)
			free((*data).img);
		if ((*data).addr != NULL)
			free((*data).addr);
	}
	if (var != NULL)
	{
		if ((*var).mlx != NULL)
			free((*var).mlx);
		if ((*var).win != NULL)
			free((*var).win);
	}
	i = 0;
	while (map != NULL && (*map).map[i] != NULL)
	{
		free((*map).map[i]);
		i ++;
	}
}

void	error_output(t_map *map, t_vars *var, t_data *data)
{
	free_structs(map, var, data);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
