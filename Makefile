NAME = so_long
SRCS = main.c event.c opt.c map.c utils.c graphic.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re

all: $(NAME)

# $(NAME): ${OBJS}
$(NAME): $(SRCS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(SRCS) -L. -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME)

# .c.o :
# 	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}


clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f libft.a
	rm -f $(NAME)

re: fclean all