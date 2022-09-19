/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:29:40 by takanoraika       #+#    #+#             */
/*   Updated: 2022/09/19 20:56:33 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}				t_data;

typedef struct s_map {
	char	**map;
	int		x;
	int		y;
}				t_map;

typedef struct s_cnts {
	int	c_cnt;
	int	e_cnt;
	int	p_cnt;
}				t_cnts;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		ply_x;
	int		ply_y;
	int		c_cnt;
	int		move_cnt;
	t_map	map;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	create_bg(t_vars vars);
void	draw_map(t_vars *vars, t_map map);
void	event_hooks(t_vars vars);
int		key_press_event(int keycode, t_vars *vars);
void	error_output(void);
int		close_win(t_vars *vars);
t_map	map_read(int fd);
int		path_check(char *path);
int		map_wall_check(t_map map);
int		map_required_check(t_map map);
void	move_up(t_vars *vars, t_map map);
void	move_left(t_vars *vars, t_map map);
void	move_right(t_vars *vars, t_map map);
void	move_down(t_vars *vars, t_map map);
void	overwrite_bg(t_vars *vars, int x, int y);
void	draw_ply(t_vars vars, int x, int y);
void	draw_exit(t_vars vars, int x, int y);

#endif