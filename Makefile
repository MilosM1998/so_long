NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = ./src/so_long.c ./utils/map_utils.c ./utils/take_map.c ./utils/init_game.c \
./utils/move.c ./utils/exit_game.c ./utils/key_hooks.c ./utils/load_next_map.c \
./utils/set_tiles.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@


$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) ./libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)


clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re