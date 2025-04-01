/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:20:35 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/01 22:25:31 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_c(t_map *map, t_game *game, int y, int x)
{
	if (map->map[y - 1][x] == '1' && map->map[y + 1][x] == '1' && map->map[y][x
		- 1] == '1' && map->map[y][x + 1] == '1')
	{
		map_error(map, game, "Collectable cannot be reached.");
	}
	map->c_count++;
	return ;
}

void	check_new_line(char *str, t_map *map)
{
	while (*str != str[ft_strlen(str) - 2])
	{
		if (*str == '\n')
		{
			map->new_line = 1;
		}
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
