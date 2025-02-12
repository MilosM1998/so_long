#include "../include/so_long.h"

void	exit_error(t_game *game, char *msg)
{
    if(game)
        free_game(game);
    ft_putendl_fd("Error:",2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void exit_program(t_game *game, char *msg, int status)
{
    if (game) {
        if (game->mlx) {
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
		ft_putendl_fd("-------> CONGRATULATIONS! YOU GOT DRUNK! <------", 1);
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

void destroy_images(t_game *game)
{
    if (!game || !game->mlx)
        return;

    if (game->player_right_standing)
        mlx_destroy_image(game->mlx, game->player_right_standing);
    if (game->player_right)
        mlx_destroy_image(game->mlx, game->player_right);
    if (game->player_left)
        mlx_destroy_image(game->mlx, game->player_left);
    if (game->player_up)
        mlx_destroy_image(game->mlx, game->player_up);
    if (game->collect_img)
        mlx_destroy_image(game->mlx, game->collect_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->floor_img)
        mlx_destroy_image(game->mlx, game->floor_img); 
}
int ft_exit(t_game *game, int which_msg)
{
    print_msg(which_msg);
    free_game(game);
    exit(0);
    return (0);
}
