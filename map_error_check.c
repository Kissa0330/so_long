/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:25:30 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/20 18:00:47 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_wall_check(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i] != NULL)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.map[i][j] != '1')
				return (-1);
			j++;
			if (i != 0 && i != map.y - 1 && j == 1)
				j = map.x - 1;
		}
		i ++;
	}
	return (0);
}

static int	cnt_obj(char map, t_cnts *cnts)
{
	if (map == 'C')
		cnts->c_cnt++;
	else if (map == 'E')
		cnts->e_cnt++;
	else if (map == 'P')
		cnts->p_cnt++;
	else if (map != '1' && map != '0')
		return (-1);
	return (0);
}

int	map_required_check(t_map map)
{
	int		i;
	int		j;
	t_cnts	cnts;

	i = 0;
	cnts.c_cnt = 0;
	cnts.e_cnt = 0;
	cnts.p_cnt = 0;
	while (map.map[i] != NULL)
	{
		j = 0;
		while (j < map.x)
		{
			if (cnt_obj(map.map[i][j], &cnts) == -1)
				return (-1);
			j ++;
		}
		i ++;
	}
	if (cnts.c_cnt == 0 || cnts.e_cnt == 0 || cnts.p_cnt != 1)
		return (-1);
	return (0);
}
