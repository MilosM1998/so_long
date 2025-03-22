/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:41:40 by mmilicev          #+#    #+#             */
/*   Updated: 2025/03/22 17:41:43 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map)
		{
			while (map->map[i])
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		free(map);
	}
}

void	map_error(t_map *map, t_game *game, char *msg)
{
	if (map)
		free_map(map);
	if (game)
		free_game(game);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

static int	is_closed_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->w_map)
	{
		if (map->map[0][i] != '1' || map->map[map->h_map - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->h_map)
	{
		if (map->map[0][i] != '1' || map->map[i][map->w_map - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_validation(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->h_map)
	{
		if ((int)ft_strlen(map->map[y]) != map->w_map)
			map_error(map, game, "Map is not rectangular.");
		while (x < map->w_map)
			init_elem(y, x++, map);
		x = 0;
		y++;
	}
	if (map->c_count < 1 || map->p_count != 1 || map->e_count != 1)
		map_error(map, game, "Map does not meet requirements.");
	if (!is_closed_by_walls(map))
		map_error(map, game, "Map is not surrounded by walls.");
	return (1);
}

t_map	*take_map(char *av, t_game *game)
{
	t_map	*map;

	map = init_map();
	if (!map)
		exit_error(game, "Initializing map failed.");
	if (!read_map(av, map, game))
		map_error(map, game, "Reading map failed.");
	if (!map_validation(map, game))
		map_error(map, game, "Invalid map.");
	return (map);
}
