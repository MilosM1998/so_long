/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:40:45 by mmilicev          #+#    #+#             */
/*   Updated: 2025/03/31 21:47:55 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_imgs(t_imgs *imgs)
{
	imgs->collect_img = NULL;
	imgs->exit_img = NULL;
	imgs->floor_img = NULL;
	imgs->wall_img = NULL;
	imgs->player_right_standing = NULL;
	imgs->player_left = NULL;
	imgs->player_right = NULL;
	imgs->player_up = NULL;
	imgs->player_default = NULL;
}

static void	set_player_imgs(t_game *game, t_imgs *imgs, int img_w, int img_h)
{
	imgs->player_right_standing = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right_standing.xpm", &img_w, &img_h);
	imgs->player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &img_w, &img_h);
	imgs->player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &img_w, &img_h);
	imgs->player_up = mlx_xpm_file_to_image(game->mlx, "textures/player_up.xpm",
			&img_w, &img_h);
	if (!imgs->player_right_standing || !imgs->player_right
		|| !imgs->player_left || !imgs->player_up)
	{
		exit_error(game, "Failed to load player textures.");
	}
}

static void	set_images(t_game *game, t_imgs *imgs, t_img_paths paths)
{
	int	img_w;
	int	img_h;

	img_w = 0;
	img_h = 0;
	imgs->collect_img = mlx_xpm_file_to_image(game->mlx, paths.collect_path,
			&img_w, &img_h);
	imgs->exit_img = mlx_xpm_file_to_image(game->mlx, paths.exit_path, &img_w,
			&img_h);
	imgs->wall_img = mlx_xpm_file_to_image(game->mlx, paths.wall_path, &img_w,
			&img_h);
	imgs->floor_img = mlx_xpm_file_to_image(game->mlx, paths.floor_path, &img_w,
			&img_h);
	set_player_imgs(game, game->imgs, img_w, img_h);
	if (!imgs->collect_img || !imgs->exit_img || !imgs->wall_img
		|| !imgs->floor_img)
	{
		exit_error(game, "Failed to load textures.");
	}
}

void	set_imgs(t_game *game)
{
	t_img_paths	paths;

	paths.collect_path = "textures/collect.xpm";
	paths.floor_path = "textures/floor.xpm";
	if (game->level == 1)
	{
		paths.exit_path = "textures/exit.xpm";
		paths.wall_path = "textures/wall.xpm";
	}
	if (game->level == 2)
	{
		paths.exit_path = "textures/map2/exit.xpm";
		paths.wall_path = "textures/map2/wall.xpm";
	}
	if (game->level == 3)
		paths.wall_path = "textures/map3/wall.xpm";
	set_images(game, game->imgs, paths);
}
