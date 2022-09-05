#include "so_long.h"

static int	map_wall_check(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (map[i][j] != '1')
				return (-1);
			j ++;
			if (i != 0 && i != x - 1)
				j = y - 1;
		}
		i ++;
	}
	return (0);
}

static int	map_required_check(char **map, int x, int y)
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
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (map[i][j] != 'C')
				req_cnt[0] ++;
			if (map[i][j] != 'E')
				req_cnt[1] ++;
			if (map[i][j] != 'P')
				req_cnt[2] ++;
			j ++;
		}
		i ++;
	}
	if (req_cnt[0] == 0 || req_cnt[1] == 0 || req_cnt[2] != 1)
		return (-1);
	return (0);
}

void	map_check(char **map, int x, int y)
{
	if (map_wall_check(map, x, y) == -1 || map_required_check(map, x, y));
		error_output(map, NULL);
	
}