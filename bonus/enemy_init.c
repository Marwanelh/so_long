/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:32:32 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	init_enemy_frame(t_game *game, t_enemy *enemy)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		enemy->frames[i] = game->monster_frames[i];
		if (!enemy->frames[i])
			ft_error_and_exit("Failed to init enemy frames");
		i++;
	}
}

static void	spawn_enemy(t_game *game, int y, int x)
{
	t_enemy	*enemy;
	int		i;

	if (game->enemy_count >= game->map.monsters)
		return ;
	enemy = &game->enemies[game->enemy_count];
	enemy->id = game->enemy_count;
	game->enemy_count++;
	enemy->x = x;
	enemy->y = y;
	enemy->dir = 1;
	enemy->start_x = x;
	enemy->start_y = y;
	enemy->is_horizontal = (x % 2 == 0);
	init_enemy_frame(game, enemy);
	i = 0;
	while (i < 4)
	{
		img_to_win(game, enemy->frames[i], x, y);
		enemy->frames[i]->instances[enemy->frames[i]->count
			- 1].enabled = (i == 0);
		i++;
	}
}

void	init_enemies(t_game *game)
{
	int	x;
	int	y;

	if (game->map.monsters == 0)
		return ;
	game->enemies = malloc(sizeof(t_enemy) * (game->map.monsters + 1));
	if (!game->enemies)
		ft_error_and_exit("Failed to allocate enemies");
	game->enemy_count = 0;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.full[y][x] == 'M')
				spawn_enemy(game, y, x);
			x++;
		}
		y++;
	}
}

void	animate_enemies(t_game *game, int old_frame)
{
	int	i;
	int	eid;

	i = 0;
	while (i < game->enemy_count)
	{
		eid = game->enemies[i].id;
		if (game->enemies[i].frames[old_frame]->instances[eid].enabled)
		{
			game->enemies[i].frames[old_frame]->instances[eid].enabled = false;
			game->enemies[i].frames[game->anim.frame]
				->instances[eid].enabled = true;
			game->enemies[i].frames[game->anim.frame]->instances[eid].x
				= game->enemies[i].frames[old_frame]->instances[eid].x;
			game->enemies[i].frames[game->anim.frame]->instances[eid].y
				= game->enemies[i].frames[old_frame]->instances[eid].y;
		}
		i++;
	}
}

void	reset_enemies(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->enemy_count)
	{
		game->enemies[i].x = game->enemies[i].start_x;
		game->enemies[i].y = game->enemies[i].start_y;
		j = 0;
		while (j < 4)
		{
			if (game->enemies[i].frames[j])
			{
				game->enemies[i].frames[j]->instances[game->enemies[i].id].x
					= game->enemies[i].start_x * 32;
				game->enemies[i].frames[j]->instances[game->enemies[i].id].y
					= game->enemies[i].start_y * 32;
			}
			j++;
		}
		i++;
	}
}
