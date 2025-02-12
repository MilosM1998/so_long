#include "../include/so_long.h"

static void	refresh_positions(t_game *game, int new_y, int new_x)
{
	game->map->map[game->map->p_y][game->map->p_x] = '0';
	game->map->p_x = new_x;
	game->map->p_y = new_y;
	game->map->map[new_y][new_x] = 'P';
	render_map(game);
}
void	*get_player_img(t_game *game)
{
	if (game->player_direction == RIGHT)
		return (game->player_right);
	else if (game->player_direction == LEFT)
		return (game->player_left);
	else if (game->player_direction == UP)
		return (game->player_up);
	else if (game->player_direction == DOWN)
		return (game->player_right_standing);
	return (game->player_right_standing);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	*moves;

	new_x = game->map->p_x + dx;
	new_y = game->map->p_y + dy;
	if (game->map->map[new_y][new_x] == '1')
		return ;
	moves = ft_itoa(game->moves);
	if(!moves)
		exit_error(game, "Itoa failed.");
	ft_putstr_fd("Moves: ", 1);
	ft_putendl_fd(moves, 1);
	game->moves++;
	free(moves);
	if (game->map->map[new_y][new_x] == 'C')
		game->beers++;
	if (game->map->map[new_y][new_x] == 'E')
	{
		if (game->beers == game->map->c_count)
		{
			game->level++;
			load_next_level(game);
		}
		return ;
	}
	refresh_positions(game, new_y, new_x);
}
