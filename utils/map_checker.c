/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:20:35 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/04 16:26:20 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**cpy_map(t_map *map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (map->h_map + 1));
	if (!map_cpy)
		return (NULL);
	while (i < map->h_map)
	{
		map_cpy[i] = ft_strdup(map->map[i]);
		if (!map_cpy[i])
		{
			while (--i >= 0)
				free(map_cpy[i]);
			free(map_cpy);
			return (NULL);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

static void	flood_fill(char **map, t_map *m, int y, int x)
{
	if (y < 0 || x < 0 || x >= m->w_map || y >= m->h_map)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, m, (y + 1), x);
	flood_fill(map, m, (y - 1), x);
	flood_fill(map, m, y, (x - 1));
	flood_fill(map, m, y, (x + 1));
}

int	check_if_reachable(t_map *map)
{
	char	**map_dup;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map_dup = cpy_map(map);
	if (!map_dup)
		return (0);
	flood_fill(map_dup, map, map->p_y, map->p_x);
	while (i < map->h_map)
	{
		j = 0;
		while (map_dup[i][j++])
		{
			if (map_dup[i][j] == 'C' || map_dup[i][j] == 'E')
			{
				free_mem(map_dup, map->h_map);
				return (0);
			}
		}
		i++;
	}
	free_mem(map_dup, map->h_map);
	return (1);
}

void	check_new_line(char *str, t_map *map)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		map->new_line = 1;
		return ;
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
			map->new_line = 1;
		str++;
	}
	return ;
}

void	new_line_error(char *str, t_map *map, t_game *game)
{
	if (map->new_line == 1)
	{
		free(str);
		map_error(map, game, "There is new line in map.");
	}
	else
		return ;
}
