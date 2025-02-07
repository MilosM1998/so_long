#include "../include/so_long.h"

static int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	print_msg(2);
	exit(0);
	return 0;
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->h_map)
	{
		j = 0;
		while (j < game->map->w_map)
		{
			if (game->map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, j
					* 50, i * 50);
			else if (game->map->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_default, j * 50, i * 50);
			else if (game->map->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, j
					* 50, i * 50);
			else if (game->map->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img,
					j * 50, i * 50);
			else if (game->map->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img, j
					* 50, i * 50);
			j++;
		}
		i++;
	}
	render_text(game);
	return (0);
}
#include <stdio.h>
int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_exit(game);
	if (keycode == W)
	{
		game->player_default = game->player_up;
		move_player(game, 0, -1);
	}
	if (keycode == A)
	{
		game->player_default = game->player_left;
		move_player(game, -1, 0);
	}
	if (keycode == S)
	{
		game->player_default = game->player_right_standing;
		move_player(game, 0, 1);
	}
	if (keycode == D)
	{
		game->player_default = game->player_right;
		move_player(game, 1, 0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game *game;
	if (ac != 2)
		exit_error("Error: Usage should be: ./so_long <map.ber>");
	game = init_game();
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Error: Failed to initialize mlx");
	game->map = take_map(av[1]);
	game->win = mlx_new_window(game->mlx, game->map->w_map * 50,//
			game->map->h_map * 50, "Take your beer");
	set_imgs(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0L, ft_exit, game);
	mlx_loop(game->mlx);
	return (0);
}