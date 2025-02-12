#include "../include/so_long.h"


static void	set_player_imgs(t_game *game, int img_w, int img_h)
{
	game->player_right_standing = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right_standing.xpm", &img_w, &img_h);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &img_w, &img_h);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &img_w, &img_h);
	game->player_up = mlx_xpm_file_to_image(game->mlx, "textures/player_up.xpm",
			&img_w, &img_h);
	if (!game->player_right_standing || !game->player_right
		|| !game->player_left || !game->player_up)
	{
		exit_error(game, "Failed to load player textures.");
	}
}

static void	set_images(t_game *game, char *collect, char *exit, char *wall,
		char *floor)
{
	int	img_w = 0, img_h;

	img_w = 0, img_h = 0;
	game->collect_img = mlx_xpm_file_to_image(game->mlx, collect, &img_w,
			&img_h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, exit, &img_w, &img_h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, wall, &img_w, &img_h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, floor, &img_w, &img_h);
	set_player_imgs(game, img_w, img_h);
	if (!game->collect_img || !game->exit_img || !game->wall_img
		|| !game->floor_img)
	{
		exit_error(game, "Failed to load textures.");
	}
}

void	set_imgs(t_game *game)
{
	if (game->level == 1)
		set_images(game, "textures/collect.xpm", "textures/exit.xpm",
			"textures/wall.xpm", "textures/floor.xpm");
	else if (game->level == 2)
		set_images(game, "textures/collect.xpm", "textures/map2/exit.xpm",
			"textures/map2/wall.xpm", "textures/floor.xpm");
	else if (game->level == 3)
		set_images(game, "textures/collect.xpm", "textures/map2/exit.xpm",
			"textures/map3/wall.xpm", "textures/floor.xpm");
}
