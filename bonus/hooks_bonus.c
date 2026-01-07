/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 04:10:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:34:20 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->game_state != STATE_PLAY)
	{
		handle_menu_input(keydata, game);
		return ;
	}
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
		}
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, game->map.p_y - 1, game->map.p_x);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, game->map.p_y, game->map.p_x - 1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, game->map.p_y + 1, game->map.p_x);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, game->map.p_y, game->map.p_x + 1);
	}
}

void	my_closehook(void *param)
{
	(void)param;
}
