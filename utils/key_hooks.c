/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:36:47 by mmilicev          #+#    #+#             */
/*   Updated: 2025/03/25 18:36:33 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook_level2(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_exit(game, GAME_OVER);
	if (keycode == W)
	{
		game->player_direction = UP;
		move_player(game, 0, 1);
	}
	if (keycode == A)
	{
		game->player_direction = LEFT;
		move_player(game, -1, 0);
	}
	if (keycode == S)
		move_player(game, 0, -1);
	if (keycode == D)
	{
		game->player_direction = RIGHT;
		move_player(game, 1, 0);
	}
	return (0);
}

int	key_hook_level3(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_exit(game, GAME_OVER);
	if (keycode == W)
	{
		game->player_direction = UP;
		move_player(game, 0, 1);
	}
	if (keycode == A)
	{
		game->player_direction = LEFT;
		move_player(game, 1, 0);
	}
	if (keycode == S)
		move_player(game, 0, -1);
	if (keycode == D)
	{
		game->player_direction = RIGHT;
		move_player(game, -1, 0);
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_exit(game, GAME_OVER);
	if (keycode == W)
	{
		game->player_direction = UP;
		move_player(game, 0, -1);
	}
	if (keycode == A)
	{
		game->player_direction = LEFT;
		move_player(game, -1, 0);
	}
	if (keycode == S)
		move_player(game, 0, 1);
	if (keycode == D)
	{
		game->player_direction = RIGHT;
		move_player(game, 1, 0);
	}
	return (0);
}
