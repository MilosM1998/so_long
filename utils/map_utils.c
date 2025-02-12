#include "../include/so_long.h"


void	init_elem(int y, int x, t_map *map)
{
	if (map->map[y][x] == 'P')
	{
		if (map->p_count != 0)
			map_error(map, NULL, "There is more then one player.");
		map->p_count++;
		map->p_y = y;
		map->p_x = x;
	}
	else if (map->map[y][x] == 'C')
		map->c_count++;
		else if (map->map[y][x] == 'E')
	{
		if (map->e_count != 0)
		map_error(map, NULL,  "There is more then one exit.");
		map->e_count++;
	}
	else if (map->map[y][x] != '1' && map->map[y][x] != '0')
	map_error(map, NULL,"Invalid characters.");
} 


static void	read_file(char *line, char **map_array, t_map *map, int fd, t_game *game)
{
	char	*tmp;
	
	tmp = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = *map_array;
		*map_array = ft_strjoin(*map_array, line);
		if(!map_array)
			exit_error(game, "Strjoin failed");
		free(tmp);
		free(line);
		map->h_map++;
	}
}


int	read_map(char *file, t_map *map, t_game *game)
{
	int		fd;
	char	*line;
	char	*map_array;
	
	line = NULL;
	map_array = ft_strdup("");
	if (!map_array)
	exit_error(game, "Error while creating array.");
	fd = open(file, O_RDONLY);
	if (fd < 0) 
		exit_error(game, "Invalid file.");
	read_file(line, &map_array, map, fd, game);
	close(fd);
	if (!map_array)
	exit_error(game, "Something went wrong while reading map.");
	map->map = ft_split(map_array, '\n');
	if(!map_array)
	exit_error(game, "Split is not allocated.");
	free(map_array);
	if (map->map)
	map->w_map = ft_strlen(map->map[0]);
	return (1);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL; 
	map->h_map = 0;
	map->w_map = 0;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
	map->p_x = -1;
	map->p_y = -1;
	return (map);
}