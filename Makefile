NAME = so_long
SRCS = main.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re

all: $(NAME)

# $(NAME): ${OBJS}
$(NAME): $(SRCS)
	$(CC) $(SRCS) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# .c.o :
# 	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all