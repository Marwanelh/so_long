/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:41:26 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#define ANIM_SPEED 20

static void	animate_player(t_game *game, int old_frame)
{
	int	i;

	i = 0;
	while (i < (int)game->player_frames[old_frame]->count)
	{
		game->player_frames[old_frame]->instances[i].enabled = false;
		i++;
	}
	i = 0;
	while (i < (int)game->player_frames[game->anim.frame]->count)
	{
		game->player_frames[game->anim.frame]->instances[i].enabled = true;
		if (i == 0 && game->player_frames[old_frame]->count > 0)
		{
			game->player_frames[game->anim.frame]->instances[0].x
				= game->player_frames[old_frame]->instances[0].x;
			game->player_frames[game->anim.frame]->instances[0].y
				= game->player_frames[old_frame]->instances[0].y;
		}
		i++;
	}
}

static void	animate_coins(t_game *game, int old_frame)
{
	int	i;
	int	gx;
	int	gy;

	i = 0;
	while (i < (int)game->coin_frames[old_frame]->count)
	{
		game->coin_frames[old_frame]->instances[i].enabled = false;
		i++;
	}
	i = 0;
	while (i < (int)game->coin_frames[game->anim.frame]->count)
	{
		gx = game->coin_frames[game->anim.frame]->instances[i].x / 32;
		gy = game->coin_frames[game->anim.frame]->instances[i].y / 32;
		if (game->map.full[gy][gx] == 'C')
			game->coin_frames[game->anim.frame]->instances[i].enabled = true;
		else
			game->coin_frames[game->anim.frame]->instances[i].enabled = false;
		i++;
	}
}

void	update_animations(void *param)
{
	t_game	*game;
	int		old_frame;

	game = (t_game *)param;
	game->anim.counter++;
	if (game->move_timer > 0)
		game->move_timer--;
	if (game->anim.counter < ANIM_SPEED)
		return ;
	game->anim.counter = 0;
	old_frame = game->anim.frame;
	game->anim.frame = (game->anim.frame + 1) % 4;
	animate_player(game, old_frame);
	animate_coins(game, old_frame);
}
