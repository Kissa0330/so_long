#include "so_long.h"


static int	map_wall_check(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.map[i][j] != '1')
				return (-1);
			j ++;
			if (i != 0 && i != map.y - 1)
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
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.map[i][j] != 'C')
				req_cnt[0] ++;
			if (map.map[i][j] != 'E')
				req_cnt[1] ++;
			if (map.map[i][j] != 'P')
				req_cnt[2] ++;
			j ++;
		}
		i ++;
	}
	if (req_cnt[0] == 0 || req_cnt[1] == 0 || req_cnt[2] != 1)
		return (-1);
	return (0);
}

t_map map_read(int fd)
{
	t_map	map;
	char	**tmp;


	map.y = 0;
	while (map.map[map.y] != NULL)
	{
		tmp = malloc(sizeof(char *) * (map.y + 2));
		if (tmp == NULL)
			error_output(map);
		tmp[map.y] = get_next_line(fd);
		cpy_map_and_free(map, tmp);
		map.y ++;
		if (map.y != 0 && map.x != ft_strlen(tmp[map.y - 1]) && tmp[map.y - 1] != NULL)
			error_output(map, NULL, NULL);
		map.x = ft_strlen((const char *)tmp[map.y]);
		map.map = tmp;
	}
	if (map_wall_check(map) == -1);
		error_output(map, NULL, NULL);
	if (map_required_check(map) == -1);
		error_output(map, NULL, NULL);
	return (map);
}
