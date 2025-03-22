/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:35:58 by mmilicev          #+#    #+#             */
/*   Updated: 2025/03/22 18:20:03 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->win && game->win)
		mlx_destroy_window(game->mlx, game->win);
	destroy_images(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
	free(game);
}

void	render_text(t_game *game)
{
	char	*beers;
	char	*total_beers;
	int		c_count;
	char	*level;

	c_count = game->map->c_count;
	beers = ft_itoa(game->beers);
	if (!beers)
		exit_error(NULL, "Itoa failed at render_text, beers array");
	total_beers = ft_itoa(c_count);
	if (!total_beers)
		exit_error(game, "itoa failed at render_text, total beers array");
	level = ft_itoa(game->level);
	if (!level)
		exit_error(game, "Itoa failed at render_text, level array.");
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

static void	*get_image(t_game *game, char elem)
{
	if (elem == 'C')
		return (game->collect_img);
	else if (elem == 'P')
		return (get_player_img(game));
	else if (elem == 'E')
		return (game->exit_img);
	else if (elem == '1')
		return (game->wall_img);
	else if (elem == '0')
		return (game->floor_img);
	return (NULL);
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
			mlx_put_image_to_window(game->mlx, game->win, get_image(game,
					game->map->map[i][j]), j * 50, i * 50);
			j++;
		}
		i++;
	}
	render_text(game);
	return (0);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_error(NULL, "Failed to allocate memory for the game.");
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Failed to load mlx");
	game->win = NULL;
	game->map = NULL;
	game->collect_img = NULL;
	game->exit_img = NULL;
	game->floor_img = NULL;
	game->moves = 0;
	game->player_right_standing = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->player_up = NULL;
	game->player_direction = RIGHT;
	game->beers = 0;
	game->total_beers = 0;
	game->level = 1;
	game->fd = 0;
	return (game);
}
