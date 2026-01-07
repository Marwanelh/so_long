/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 04:07:38 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static mlx_image_t	*load_raw_png(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!img)
	{
		ft_error_and_exit("Failed to create image from texture");
	}
	return (img);
}

static mlx_image_t	*load_sprite(t_game *game, char *path)
{
	mlx_image_t	*img;

	img = load_raw_png(game, path);
	if (img)
	{
		if (!mlx_resize_image(img, 32, 32))
			ft_error_and_exit("Failed to resize sprite");
		remove_background(img);
	}
	return (img);
}

static void	init_static_images(t_game *game)
{
	game->floor_frames[0] = load_sprite(game, "./textures/floor_3.png");
	game->floor_frames[1] = load_sprite(game, "./textures/floor_3.png");
	game->floor_frames[2] = load_sprite(game, "./textures/floor_3.png");
	game->floor_frames[3] = load_sprite(game, "./textures/floor_3.png");
	game->wall_frames[0] = load_sprite(game, "./textures/wall_0.png");
	game->wall_frames[1] = load_sprite(game, "./textures/wall_0.png");
	game->wall_frames[2] = load_sprite(game, "./textures/wall_0.png");
	game->wall_frames[3] = load_sprite(game, "./textures/wall_0.png");
	game->door = load_sprite(game, "./textures/door.png");
	game->img_start = load_raw_png(game, "./textures/start_screen.png");
	game->img_gameover = load_raw_png(game, "./textures/you_died.png");
}

static void	init_animation_frames(t_game *game)
{
	game->player_frames[0] = load_sprite(game, "./textures/player_0.png");
	game->player_frames[1] = load_sprite(game, "./textures/player_1.png");
	game->player_frames[2] = load_sprite(game, "./textures/player_2.png");
	game->player_frames[3] = load_sprite(game, "./textures/player_3.png");
	game->coin_frames[0] = load_sprite(game, "./textures/coin_0.png");
	game->coin_frames[1] = load_sprite(game, "./textures/coin_1.png");
	game->coin_frames[2] = load_sprite(game, "./textures/coin_2.png");
	game->coin_frames[3] = load_sprite(game, "./textures/coin_3.png");
	game->monster_frames[0] = load_sprite(game, "./textures/monster_0.png");
	game->monster_frames[1] = load_sprite(game, "./textures/monster_1.png");
	game->monster_frames[2] = load_sprite(game, "./textures/monster_2.png");
	game->monster_frames[3] = load_sprite(game, "./textures/monster_3.png");
	game->key_frames[0] = load_sprite(game, "./textures/keys/keys_1_1.png");
	game->key_frames[1] = load_sprite(game, "./textures/keys/keys_1_2.png");
	game->key_frames[2] = load_sprite(game, "./textures/keys/keys_1_3.png");
	game->key_frames[3] = load_sprite(game, "./textures/keys/keys_1_4.png");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.cols * 32, game->map.rows * 32, "so_long",
			true);
	if (!game->mlx)
		ft_error_and_exit("MLX Init Failed");
	init_static_images(game);
	init_animation_frames(game);
	init_music(game);
	game->moves = 0;
	game->move_timer = 0;
	game->has_key = 0;
	game->move_display = NULL;
}
