/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:56:32 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/04 16:11:08 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define RIGHT 1
# define LEFT 2
# define UP 3
# define DOWN 4
# define MAX_LEVEL 3
# define WIN_MSG 1
# define GAME_OVER 2

typedef struct s_map
{
	char	**map;
	int		w_map;
	int		h_map;
	int		c_count;
	int		p_count;
	int		e_count;
	int		p_x;
	int		p_y;
	int		new_line;
	int		isleveledmap;
}			t_map;

typedef struct s_imgs
{
	void	*exit_img;
	void	*collect_img;
	void	*floor_img;
	void	*wall_img;
	void	*player_default;
	void	*player_right_standing;
	void	*player_left;
	void	*player_right;
	void	*player_up;
}			t_imgs;

typedef struct s_game
{
	t_map	*map;
	int		moves;
	int		fd;
	void	*mlx;
	void	*win;
	int		beers;
	int		total_beers;
	int		level;
	int		player_direction;
	t_imgs	*imgs;
}			t_game;

typedef struct s_img_paths
{
	char	*exit_path;
	char	*collect_path;
	char	*floor_path;
	char	*wall_path;
}			t_img_paths;

t_game		*init_game(void);
t_map		*init_map(int is_leveled);
t_map		*take_map(char *av, t_game *game);

void		init_imgs(t_imgs *imgs);
void		free_game(t_game *game);
void		map_error(t_map *map, t_game *game, char *msg);
void		free_map(t_map *map);
void		init_elem(int i, int j, t_map *map, t_game *game);

void		destroy_images(t_game *game);
void		exit_error(t_game *game, char *msg);
void		print_msg(int msg);
void		move_player(t_game *game, int dx, int dy);
void		set_imgs(t_game *game);
void		render_text(t_game *game);
void		destroy_images(t_game *game);
void		load_next_level(t_game *game);
void		*get_player_img(t_game *game);
void		check_new_line(char *str, t_map *map);
void		new_line_error(char *str, t_map *map, t_game *game);

int			map_validation(t_map *map, t_game *game);
int			read_map(char *file, t_map *map, t_game *game);
int			render_map(t_game *game);
int			ft_exit(t_game *game, int which_msg);
int			key_hook(int keycode, t_game *game);
int			key_hook_level2(int keycode, t_game *game);
int			key_hook_level3(int keycode, t_game *game);
int			check_if_reachable(t_map *map);

#endif