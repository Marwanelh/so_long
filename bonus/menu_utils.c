/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 04:41:00 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/10 04:41:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_image_alpha(mlx_image_t *img, int alpha)
{
	uint32_t	x;
	uint32_t	y;
	uint8_t		*pixel;

	if (!img)
		return ;
	if (alpha < 0)
		alpha = 0;
	if (alpha > 255)
		alpha = 255;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = &img->pixels[((y * img->width) + x) * sizeof(int32_t)];
			pixel[3] = (uint8_t)alpha;
			x++;
		}
		y++;
	}
}

void	setup_menu_image(t_game *game, mlx_image_t *img)
{
	if (!img)
		return ;
	if (!mlx_resize_image(img, game->map.cols * 32, game->map.rows * 32))
	{
		ft_putstr_fd("Failed to resize menu image\n", 2);
		return ;
	}
	mlx_image_to_window(game->mlx, img, 0, 0);
	set_image_alpha(img, 0);
	img->instances[0].enabled = false;
}

void	reset_game(t_game *game)
{
	int	i;

	game->map.p_x = game->spawn_x;
	game->map.p_y = game->spawn_y;
	i = 0;
	while (i < 4)
	{
		game->player_frames[i]->instances[0].x = game->spawn_x * 32;
		game->player_frames[i]->instances[0].y = game->spawn_y * 32;
		game->player_frames[i]->instances[0].enabled = (i == 0);
		i++;
	}
	game->moves = 0;
	reset_coins(game);
	reset_key(game);
	reset_enemies(game);
	ft_putstr_fd("Game Restarted!\n", 1);
}
