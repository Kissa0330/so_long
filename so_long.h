#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_press_event(int keycode, t_vars *vars);
void	close_win(t_vars *vars);

#endif