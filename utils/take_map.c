#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->map)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
	free(map);
}

void	error(t_map *map, char *msg)
{
	free_map(map);
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
#include <stdio.h>
int	map_validation(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->h_map)
	{
		if ((int)ft_strlen(map->map[y]) != map->w_map)
			error(map, "Error: Map is not rectangular.");
		while (x < map->w_map)
			init_elem(y, x++, map);
		printf("Player position: y:%d, x:%d\n", map->p_y, map->p_x);
		x = 0;
		y++;
	} 
	if (map->c_count < 1 || map->p_count != 1 || map->e_count != 1)
		error(map, "Error:Map does not meet requirements.");
	if (!is_closed_by_walls(map))
		error(map, "Error: Map is not surrounded by walls.");
	return (1);
}
t_map	*take_map(char *av)
{
	int		i;
	t_map	*map;

	i = 0;
	map = init_map();
	if (!map)
	{
		ft_putendl_fd("Error: Memory allocation failed.", 2);
		exit(1);
	}
	if (!read_map(av, map))
		error(map, "Error: Failed reading map");
	if (!map_validation(map))
		error(map, "Error: Invalid map.");
	while (i < map->h_map)
		ft_putendl_fd(map->map[i++], 1);
	return (map);
}
