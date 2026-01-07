/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 04:30:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static mlx_image_t	*load_png(t_game *game, char *path)
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
		ft_error_and_exit("Failed to create image from texture");
	if (!mlx_resize_image(img, 32, 32))
		ft_error_and_exit("Failed to resize sprite");
	remove_background(img);
	return (img);
}

void	init_images(t_game *game)
{
	int	i;

	game->floor_frames[0] = load_png(game, "textures/floor_3.png");
	game->wall_frames[0] = load_png(game, "textures/wall_0.png");
	game->door = load_png(game, "textures/door.png");
	game->key_frames[0] = load_png(game, "textures/keys/keys_1_1.png");
	load_player_sprites(game, load_png);
	load_coin_sprites(game, load_png);
	i = 1;
	while (i < 4)
	{
		game->floor_frames[i] = NULL;
		game->wall_frames[i] = NULL;
		game->key_frames[i] = NULL;
		i++;
	}
	game->anim.frame = 0;
	game->anim.counter = 0;
	game->move_timer = 0;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.cols * 32, game->map.rows * 32, "so_long",
			true);
	if (!game->mlx)
		ft_error_and_exit("MLX Init Failed");
	game->has_key = 0;
	game->moves = 0;
	init_images(game);
}
