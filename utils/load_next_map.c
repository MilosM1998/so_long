/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_next_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:37:36 by mmilicev          #+#    #+#             */
/*   Updated: 2025/03/31 20:34:31 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*prepare_map(t_game *game)
{
	char	*level;
	char	*next_map;
	char	*full_map;

	level = ft_itoa(game->level);
	if (!level)
		exit_error(game, "Itoa failed at prepare_map.");
	next_map = ft_strjoin("./maps/map", level);
	if (!next_map)
		exit_error(game, "Strjoin failed at prepare_map");
	full_map = ft_strjoin(next_map, ".ber");
	if (!full_map)
		exit_error(game, "Strjoin failed at prepare_map");
	free(level);
	free(next_map);
	return (full_map);
}

static void	load_map(t_game *game, char *full_map)
{
	free_map(game->map);
	destroy_images(game);
	game->imgs = NULL;
	if (game->level != 4)
	{
		game->imgs = malloc(sizeof(t_imgs));
		if (!game->imgs)
			exit_error(game, "Malloc failed to allocate imgs for next level.");
	}
	game->map = take_map(full_map, game);
	if (!game->map)
		exit_error(game, "Error while loading next map.");
	free(full_map);
}

static void	set_level(t_game *game)
{
	set_imgs(game);
	if (game->level == 2)
		mlx_hook(game->win, 2, 1L << 0, key_hook_level2, game);
	else if (game->level == 3)
		mlx_hook(game->win, 2, 1L << 0, key_hook_level3, game);
}

void	load_next_level(t_game *game)
{
	if (game->level > MAX_LEVEL)
		ft_exit(game, WIN_MSG);
	game->total_beers = 0;
	game->beers = 0;
	load_map(game, prepare_map(game));
	set_level(game);
	render_map(game);
}
