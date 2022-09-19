/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:26:37 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 23:36:48 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	del_line_char(char *str)
{
	char	*line_point;

	if (str == NULL)
		return ;
	line_point = ft_strchr(str, '\n');
	if (line_point != NULL)
		line_point[0] = '\0';
}

static void	read_map_and_free(t_map *map, int fd)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (map->y) + 1);
	if (tmp == NULL)
		error_output();
	tmp[map->y] = NULL;
	tmp[map->y - 1] = get_next_line(fd);
	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i] != NULL)
		{
			tmp[i] = map->map[i];
			i ++;
		}
		free(map->map);
	}
	del_line_char(tmp[i]);
	map->map = tmp;
}

static void	map_check(t_map map)
{
	if (map_wall_check(map) == -1)
		error_output();
	if (map_required_check(map) == -1)
		error_output();
}

t_map	map_read(int fd)
{
	t_map	map;

	map.y = 1;
	map.map = NULL;
	read_map_and_free(&map, fd);
	if (ft_strlen((const char *)map.map[map.y - 1]) > INT_MAX)
		error_output();
	map.x = ft_strlen((const char *)map.map[map.y - 1]);
	while (map.map[map.y - 1] != NULL)
	{
		map.y ++;
		read_map_and_free(&map, fd);
		if (map.map[map.y - 1] != NULL)
		{
			if (map.x != (int)ft_strlen(map.map[map.y - 1]))
			{
				if (map.map[map.y - 1] != NULL)
					error_output();
			}
			map.x = ft_strlen(map.map[map.y - 1]);
		}
	}
	map_check(map);
	return (map);
}
