NAME = so_long
SRCS = main.c event.c opt.c map.c utils.c graphic_init.c graphic_in_game.c error_check.c map_error_check.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra
#  -fsanitize=address

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	make -C minilibx_opengl
	cp ./libft/libft.a .
	cp ./minilibx_opengl/libmlx.a .
	$(CC) $(CFLAGS) $(SRCS) -L. -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME)



clean:
	make -C libft clean
	make -C minilibx_opengl clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f libft.a
	rm -f libmlx.a
	rm -f $(NAME)

re: fclean all