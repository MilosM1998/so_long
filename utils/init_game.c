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
	game->player_right_standing = NULL;
	game->player_left_standing = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->player_up = NULL;
	game->player_default = NULL;
	game->beers = 0;
	game->total_beers = 0;
	game->level = 1;
	return (game);
}

static void	set_player_imgs(t_game *game, int img_w, int img_h)
{
	game->player_right_standing = mlx_xpm_file_to_image(game->mlx,
		"textures/player_right_standing.xpm", &img_w, &img_h);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
		"textures/player_right.xpm", &img_w, &img_h);
	game->player_left_standing = mlx_xpm_file_to_image(game->mlx,
		"textures/player_left_standing.xpm", &img_w, &img_h);
	game->player_left = mlx_xpm_file_to_image(game->mlx, "textures/player_left.xpm", &img_w, &img_h);
	game->player_up = mlx_xpm_file_to_image(game->mlx, "textures/player_up.xpm", &img_w, &img_h);
	if(!game->player_right_standing || !game->player_right || !game->player_right /
		!game->player_left_standing || !game->player_left || !game->player_up )
		exit_error("Error: Failed to load textures.");
}

void	render_text(t_game *game)
{
	char *beers;
	char *total_beers;
	int		c_count;
	char *level;

	c_count = game->map->c_count;
	beers = ft_itoa(game->beers);
	total_beers = ft_itoa(c_count);
	level = ft_itoa(game->level);

	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Beers:");
	mlx_string_put(game->mlx, game->win, 90, 10, 0xFFFFFF, beers);
	mlx_string_put(game->mlx, game->win, 110, 10, 0xFFFFFF, "/");
	mlx_string_put(game->mlx, game->win, 120, 10, 0xFFFFFF, total_beers);

	mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, "Level: ");
	mlx_string_put(game->mlx, game->win, 80, 30, 0xFFFFFF, level);
	free(beers);
	free(total_beers);
	free(level);
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
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall_x.xpm",
			&img_w, &img_h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&img_w, &img_h);
	set_player_imgs(game, img_w, img_h);
	game->player_default = game->player_right_standing;
	if (!game->collect_img || !game->exit_img || \
		 !game->wall_img || !game->floor_img || !game->player_default)
		exit_error("Error: Failed to load textures.");
}


