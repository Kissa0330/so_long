#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_vars;

typedef struct	s_map {
	char	**map;
	int		x;
	int		y;
}				t_map;

# include "mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_press_event(int keycode, t_vars *vars);
void	free_structs(t_map *map, t_vars *var, t_data *data);
void	error_output(t_map *map, t_vars *var, t_data *data);
int		close_win(t_vars *vars);
t_map	map_read(int fd);

#endif