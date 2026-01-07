/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 04:40:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

#define ANIM_SPEED 20

static void	handle_player_animation(t_game *game, int old_frame)
{
	game->player_frames[old_frame]->instances[0].enabled = false;
	game->player_frames[game->anim.frame]->instances[0].enabled = true;
	game->player_frames[game->anim.frame]->instances[0].x
		= game->player_frames[old_frame]->instances[0].x;
	game->player_frames[game->anim.frame]->instances[0].y
		= game->player_frames[old_frame]->instances[0].y;
}

static void	handle_coin_animation(t_game *game, int old_frame)
{
	size_t	i;

	i = 0;
	while (i < game->coin_frames[old_frame]->count)
	{
		if (game->coin_frames[old_frame]->instances[i].enabled)
		{
			game->coin_frames[old_frame]->instances[i].enabled = false;
			game->coin_frames[game->anim.frame]->instances[i].enabled = true;
		}
		i++;
	}
}

static void	handle_key_animation(t_game *game, int old_frame)
{
	size_t	i;

	i = 0;
	while (i < game->key_frames[old_frame]->count)
	{
		if (game->key_frames[old_frame]->instances[i].enabled)
		{
			game->key_frames[old_frame]->instances[i].enabled = false;
			game->key_frames[game->anim.frame]->instances[i].enabled = true;
		}
		i++;
	}
}

void	update_animations(void *param)
{
	t_game	*game;
	int		old_frame;

	game = (t_game *)param;
	if (game->move_timer > 0)
		game->move_timer--;
	move_enemies(game);
	update_fade(game);
	game->anim.counter++;
	if (game->anim.counter >= ANIM_SPEED)
	{
		old_frame = game->anim.frame;
		game->anim.frame = (game->anim.frame + 1) % 4;
		game->anim.counter = 0;
		handle_player_animation(game, old_frame);
		handle_coin_animation(game, old_frame);
		handle_key_animation(game, old_frame);
		animate_enemies(game, old_frame);
	}
}
