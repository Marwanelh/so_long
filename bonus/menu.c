/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 04:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 04:53:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_fade(t_game *game)
{
	double	speed;

	if (game->fade_dir == 0 || !game->img_fade)
		return ;
	speed = 2.0 * game->mlx->delta_time;
	game->fade_alpha += (game->fade_dir * speed);
	if (game->fade_alpha >= 1.0)
		game->fade_alpha = 1.0;
	else if (game->fade_alpha < 0.0)
		game->fade_alpha = 0.0;
	if (game->fade_dir == -1 && game->fade_alpha == 0.0)
	{
		game->fade_dir = 0;
		game->img_fade->instances[0].enabled = false;
		game->img_fade = NULL;
		return ;
	}
	set_image_alpha(game->img_fade, (int)(game->fade_alpha * 255));
}

void	init_menus(t_game *game)
{
	setup_menu_image(game, game->img_start);
	setup_menu_image(game, game->img_gameover);
	game->fade_alpha = 0.0;
	game->fade_dir = 0;
	game->img_fade = NULL;
}

void	toggle_menus(t_game *game)
{
	if (game->game_state == STATE_START)
	{
		if (!game->img_start)
			return ;
		game->img_fade = game->img_start;
		game->img_fade->instances[0].enabled = true;
		game->fade_dir = 1;
		game->fade_alpha = 1.0;
		set_image_alpha(game->img_fade, 255);
	}
	if (game->game_state == STATE_PLAY)
	{
		if (game->img_fade)
			game->fade_dir = -1;
	}
	if (game->game_state == STATE_GAMEOVER)
	{
		if (!game->img_gameover)
			return ;
		game->img_fade = game->img_gameover;
		game->img_fade->instances[0].enabled = true;
		game->fade_dir = 1;
		game->fade_alpha = 1.0;
		set_image_alpha(game->img_fade, 255);
	}
}

void	handle_menu_input(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_PRESS)
	{
		if (game->game_state == STATE_START)
		{
			game->game_state = STATE_PLAY;
			toggle_menus(game);
			ft_putstr_fd("Game Started!\n", 1);
			return ;
		}
		game->game_state = STATE_PLAY;
		reset_game(game);
		toggle_menus(game);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
	}
}
