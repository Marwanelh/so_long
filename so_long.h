/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:59:46 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_map
{
	char		**full;
	int			rows;
	int			cols;
	int			coins;
	int			exit;
	int			players;
	int			p_x;
	int			p_y;
	int			monsters;
}				t_map;

typedef struct s_anim
{
	int			frame;
	int			counter;
}				t_anim;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			dir;
	int			id;
	int			is_horizontal;
	int			start_x;
	int			start_y;
	mlx_image_t	*frames[4];
}				t_enemy;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		map;
	mlx_image_t	*wall_frames[4];
	mlx_image_t	*floor_frames[4];
	mlx_image_t	*door;
	mlx_image_t	*player_frames[4];
	mlx_image_t	*coin_frames[4];
	mlx_image_t	*monster_frames[4];
	t_enemy		*enemies;
	int			enemy_count;
	int			enemy_move_timer;
	mlx_image_t	*move_display;
	int			moves;
	int			has_key;
	mlx_image_t	*key_frames[4];
	t_anim		anim;
	int			move_timer;
	int			spawn_x;
	int			spawn_y;
	// Bonus: Game State
	int			game_state;
	mlx_image_t	*img_start;
	mlx_image_t	*img_gameover;
	mlx_image_t	*menu_images[10];

	// Bonus: Fade Animation
	double		fade_alpha;
	int			fade_dir;
	mlx_image_t	*img_fade;

	int			fd;
	pid_t		music_pid;
}				t_game;

enum			e_game_state
{
	STATE_START = 0,
	STATE_PLAY = 1,
	STATE_GAMEOVER = 2
};

void			init_game(t_game *game);
int				check_map(t_game *game);
int				map_reading(t_game *game, char **argv);
int				check_path(t_game *game);
void			render_map(t_game *game);
void			move_player(t_game *game, int next_y, int next_x);
void			img_to_win(t_game *game, mlx_image_t *img, int x, int y);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			my_closehook(void *param);
void			update_animations(void *param);

void			process_pixel(mlx_image_t *img, uint32_t x, uint32_t y,
					uint8_t bg[3]);
void			remove_background(mlx_image_t *img);
void			load_player_sprites(t_game *game,
					mlx_image_t *(*loader)(t_game *, char *));
void			load_coin_sprites(t_game *game, mlx_image_t *(*loader)(t_game *,
						char *));

void			ft_error_and_exit(char *msg);
void			ft_trim_cr(char *s);
char			*get_next_line(int fd);
void			free_map_copy(char **map, int rows);

#endif
