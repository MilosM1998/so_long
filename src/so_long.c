#include "../include/so_long.h"

static void	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	print_msg(2);
	exit(0);
}

void	set_imgs(t_game *game)
{
	int	img_w;
	int	img_h;

	img_h = 0;
	img_w = 0;
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&img_w, &img_h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&img_w, &img_h);
	game->player_set[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &img_w, &img_h);
	game->player_set[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/player2.xpm", &img_w, &img_h);
	game->player_set[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/player3.xpm", &img_w, &img_h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall_x.xpm",
			&img_w, &img_h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&img_w, &img_h);
	if (!game->collect_img || !game->exit_img || !game->player_set[0] \
		|| !game->wall_img || !game->floor_img || !game->player_set[1] \
		|| !game->player_set[2])
		exit_error("Error: Failed to load textures.");
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
					game->player_set[game->curr_player], j * 50, i * 50);
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
	return (0);
}
int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_exit(game);
	if (keycode == W)
		move_player(game, 0, -1);
	if (keycode == A)
		move_player(game, -1, 0);
	if (keycode == S)
		move_player(game, 0, 1);
	if (keycode == D)
		move_player(game, 1, 0);
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
	game->win = mlx_new_window(game->mlx, game->map->w_map * 50,
			game->map->h_map * 50, "Take your beer");
	set_imgs(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}