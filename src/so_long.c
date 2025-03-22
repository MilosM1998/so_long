/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:34:06 by mmilicev          #+#    #+#             */
/*   Updated: 2025/03/22 17:34:09 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_map_file(char *av)
{
	char	*file_ext;
	int		fd;

	file_ext = ft_strrchr(av, '.');
	if (av[0] != '.' || av[1] != '/')
	{
		ft_putendl_fd("Error:\nMap file must start with './'. ", 2);
		return (1);
	}
	if (!file_ext || ft_strncmp(file_ext, ".ber", 4) != 0)
	{
		ft_putendl_fd("Error\nMap must be type '.ber'.", 2);
		return (1);
	}
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error:\nFile does not exist or cannot be opened.", 2);
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_putendl_fd("Error:\nUsage should be: ./so_long <map.ber>", 2);
		return (1);
	}
	if (check_map_file(av[1]))
		return (1);
	game = init_game();
	if (!game)
		return (1);
	game->map = take_map(av[1], game);
	if (!game->map)
		exit_error(game, "Map cannot be readen.");
	game->win = mlx_new_window(game->mlx, game->map->w_map * 50,
			game->map->h_map * 50, "Take your beer");
	set_imgs(game);
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 0L, ft_exit, game);
	mlx_loop(game->mlx);
	return (0);
}
