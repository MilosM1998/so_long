/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:35:17 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/01 22:24:46 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_error(t_game *game, char *msg)
{
	if (game)
		free_game(game);
	ft_putendl_fd("Error:", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	exit_program(t_game *game, char *msg, int status)
{
	if (game)
	{
		if (game->mlx)
		{
			destroy_images(game);
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
		}
		if (game->map)
			free_map(game->map);
		free(game);
	}
	ft_putendl_fd("Error:", 2);
	ft_putendl_fd(msg, 2);
	exit(status);
}

void	print_msg(int msg)
{
	if (msg == 1)
	{
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("---> CONGRATULATIONS! YOU SURVIVED SOMEHOW! <---", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
	}
	if (msg == 2)
	{
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("-------------> G A M E  O V E R <---------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
		ft_putendl_fd("------------------------------------------------", 1);
	}
}

void	destroy_images(t_game *game)
{
	if (!game || !game->mlx || !game->imgs)
		return ;
	if (game->imgs->player_right_standing)
		mlx_destroy_image(game->mlx, game->imgs->player_right_standing);
	if (game->imgs->player_right)
		mlx_destroy_image(game->mlx, game->imgs->player_right);
	if (game->imgs->player_left)
		mlx_destroy_image(game->mlx, game->imgs->player_left);
	if (game->imgs->player_up)
		mlx_destroy_image(game->mlx, game->imgs->player_up);
	if (game->imgs->collect_img)
		mlx_destroy_image(game->mlx, game->imgs->collect_img);
	if (game->imgs->exit_img)
		mlx_destroy_image(game->mlx, game->imgs->exit_img);
	if (game->imgs->wall_img)
		mlx_destroy_image(game->mlx, game->imgs->wall_img);
	if (game->imgs->floor_img)
		mlx_destroy_image(game->mlx, game->imgs->floor_img);
	if (game->imgs)
		free(game->imgs);
}

int	ft_exit(t_game *game, int which_msg)
{
	print_msg(which_msg);
	free_game(game);
	exit(0);
	return (0);
}
