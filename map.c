/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:26:37 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 10:41:23 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_wall_check(t_map map)
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

static int	map_required_check(t_map map)
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

	tmp = malloc(sizeof(char *) * ((*map).y) + 1);
	if (tmp == NULL)
		error_output();
	tmp[(*map).y] = NULL;
	tmp[(*map).y - 1] = get_next_line(fd);
	i = 0;
	if ((*map).map != NULL)
	{
		while ((*map).map[i] != NULL)
		{
			tmp[i] = (*map).map[i];
			i ++;
		}
		free((*map).map);
	}
	del_line_char(tmp[i]);
	(*map).map = tmp;
}

t_map	map_read(int fd)
{
	t_map	map;

	map.y = 1;
	map.map = NULL;
	read_map_and_free(&map, fd);
	map.x = ft_strlen((const char *)map.map[map.y - 1]);
	while (map.map[map.y - 1] != NULL)
	{
		map.y ++;
		read_map_and_free(&map, fd);
		if (map.map[map.y - 1] != NULL)
		{
			if (map.x != (int)ft_strlen(map.map[map.y - 1]) && map.map[map.y - 1] != NULL)
				error_output();
			map.x = ft_strlen(map.map[map.y - 1]);
		}
	}
	if (map_wall_check(map) == -1)
		error_output();
	if (map_required_check(map) == -1)
		error_output();
	return (map);
}

/*
//TODO mapがゴール可能かどうかを確かめる処理,xがintを超えた場合のエラー処理、関数の分割、地図が指定されている文字のみで構成されているかのチェック
//MEMO mapのゴール可否を判断する際は迷路を解くアルゴリズムなどが役に立つかも？
int	main()
{
	t_map	map;
	char	*line;
	int		i;
	int		fd;

	fd = open("map.bar", O_RDONLY);
	map = map_read(fd);
	i = 0;
	while (map.map[i] != NULL)
	{
		printf("%s\n", map.map[i]);
		i ++;
	}
	return (0);
}
*/
