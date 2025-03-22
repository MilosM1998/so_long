/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:40:45 by mmilicev          #+#    #+#             */
/*   Updated: 2025/03/22 19:18:06 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	set_images(t_game *game)
{
	int	img_w;
	int	img_h;

	img_w = 0;
	img_h = 0;
	game->imgs->collect_img = mlx_xpm_file_to_image(game->mlx, game->imgs->collect_img, &img_w,
			&img_h);
	game->imgs->exit_img = mlx_xpm_file_to_image(game->mlx, game->imgs->exit_img, &img_w, &img_h);
	game->imgs->wall_img = mlx_xpm_file_to_image(game->mlx, game->imgs->wall_img, &img_w, &img_h);
	game->imgs->floor_img = mlx_xpm_file_to_image(game->mlx, game->imgs->floor_img, &img_w, &img_h);
	set_player_imgs(game, img_w, img_h);
	if (!game->imgs->collect_img || !game->imgs->exit_img || !game->imgs->wall_img
		|| !game->imgs->floor_img)
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
