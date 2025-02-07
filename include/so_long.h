#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK 0xFF023040
# define W 119
# define A 97
# define S 115
# define D 100
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
}			t_map;

typedef struct s_game
{
	t_map	*map;
	int		moves;
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*player_default;
	void	*player_right_standing;
	void	*player_left_standing;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*exit_img;
	void	*collect_img;
	void	*floor_img;
	int		 beers;
	int		 total_beers;
	int		 level;
}			t_game;

t_map		*init_map(void);
int			map_validation(t_map *map);
int			read_map(char *file, t_map *map);
void		error(t_map *map, char *msg);
void		free_map(t_map *map);
void		init_elem(int i, int j, t_map *map);
t_map		*take_map(char *av);
t_game		*init_game(void);
void		exit_error(char *msg);
void		print_msg(int msg);
int			render_map(t_game *game);
void		move_player(t_game *game, int dx, int dy);
void	set_imgs(t_game *game);
void	render_text(t_game *game);

#endif