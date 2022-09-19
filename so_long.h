#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}				t_data;

typedef struct	s_map {
	char	**map;
	int		x;
	int		y;
}				t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		ply_x;
	int		ply_y;
	t_map	map;
}				t_vars;

# include "mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_bg(t_vars vars);
void	draw_map(t_vars *vars, t_map map);
void	event_hooks(t_vars vars);
int		key_press_event(int keycode, t_vars *vars);
void	error_output();
int		close_win(t_vars *vars);
t_map	map_read(int fd);
int		path_check(char *path);
int		map_wall_check(t_map map);
int		map_required_check(t_map map);
void	move_up(t_vars *vars, t_map map);
void	overwrite_bg(t_vars *vars, int x, int y);

#endif