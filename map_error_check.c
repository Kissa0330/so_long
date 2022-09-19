/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:25:30 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 14:25:55 by takanoraika      ###   ########.fr       */
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

int	map_required_check(t_map map)
{
	int	i;
	int	j;
	int	req_cnt[3];

	i = 0;
	while (i < 3)
	{
		req_cnt[i] = 0;
		i ++;
	}
	i = 0;
	while (map.map[i] != NULL)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.map[i][j] == 'C')
				req_cnt[0]++;
			else if (map.map[i][j] == 'E')
				req_cnt[1]++;
			else if (map.map[i][j] == 'P')
				req_cnt[2]++;
			else if (map.map[i][j] != '1' && map.map[i][j] != '0')
				return (-1);
			j ++;
		}
		i ++;
	}
	if (req_cnt[0] == 0 || req_cnt[1] == 0 || req_cnt[2] != 1)
		return (-1);
	return (0);
}
