#include "../include/so_long.h"

void	exit_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_error("Error: Failed to allocate memory for the game.");
	game->win = NULL;
	game->collect_img = NULL;
	game->exit_img = NULL;
	game->mlx = NULL;
	game->moves = 0;
	game->curr_player = 0;
	return (game);
}
