#include "../include/so_long.h"
#include <stdio.h>

void	print_msg(int msg)
{
	if (msg == 1)
	{
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("-------> CONGRATULATIONS! YOU GOT DRUNK! <------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
	}
	if (msg == 2)
	{
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("-------------> G A M E  O V E R <---------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
	}
}

static void	refresh_positions(t_game *game, int new_y, int new_x)
{
	game->map->map[game->map->p_y][game->map->p_x] = '0';
	game->map->p_x = new_x;
	game->map->p_y = new_y;
	game->map->map[new_y][new_x] = 'P';
	render_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->p_x + dx;
	new_y = game->map->p_y + dy;
	if (game->map->map[new_y][new_x] == '1')
		return ;
	ft_putstr_fd("Moves: ", 1);
	ft_putendl_fd(ft_itoa(game->moves), 1);
	game->moves++;
	if (game->map->map[new_y][new_x] == 'C')
		game->map->c_count--;
	if (game->map->map[new_y][new_x] == 'E')
	{
		if (game->map->c_count == 0)
		{
			print_msg(1);
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		return ;
	}
	refresh_positions(game, new_y, new_x);
	game->curr_player = (game->curr_player + 1) % 3;
}
