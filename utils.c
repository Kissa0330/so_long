#include "so_long.h"

void	free_structs(t_map *map, t_vars *var, t_data *data)
{
	int	i;

	if ((*data).img != NULL && data != NULL)
		free((*data).img);
	if ((*data).addr != NULL && data != NULL)
		free((*data).addr);
	if ((*var).mlx != NULL && var != NULL)
		free((*var).mlx);
	if ((*var).win != NULL && var != NULL)
		free((*var).win);
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
	write(2 ,"Error\n", 6);
	exit(EXIT_FAILURE);
}