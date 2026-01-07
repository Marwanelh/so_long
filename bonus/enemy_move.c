/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:34:08 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	handle_player_collision(t_game *game)
{
	ft_putstr_fd("Monster caught you! GAME OVER\n", 1);
	game->game_state = STATE_GAMEOVER;
	toggle_menus(game);
}

static void	update_enemy_pos(t_enemy *enemy, int next_x, int next_y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (enemy->frames[i] && (size_t)enemy->id < enemy->frames[i]->count)
		{
			enemy->frames[i]->instances[enemy->id].x = next_x * 32;
			enemy->frames[i]->instances[enemy->id].y = next_y * 32;
		}
		i++;
	}
	enemy->x = next_x;
	enemy->y = next_y;
}

static int	is_valid_move(t_game *game, int x, int y)
{
	char	tile;

	if (x < 0 || y < 0 || x >= game->map.cols || y >= game->map.rows)
		return (0);
	tile = game->map.full[y][x];
	if (tile == '1' || tile == 'E')
		return (0);
	return (1);
}

static void	chase_player(t_game *game, t_enemy *enemy)
{
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;

	if (enemy->x == game->map.p_x && enemy->y == game->map.p_y)
		return ((void)handle_player_collision(game));
	dx = game->map.p_x - enemy->x;
	dy = game->map.p_y - enemy->y;
	step_x = (abs(dx) > abs(dy)) * ((dx > 0) - (dx < 0));
	step_y = (abs(dx) <= abs(dy)) * ((dy > 0) - (dy < 0));
	if (step_x && is_valid_move(game, enemy->x + step_x, enemy->y))
		update_enemy_pos(enemy, enemy->x + step_x, enemy->y);
	else if (step_y && is_valid_move(game, enemy->x, enemy->y + step_y))
		update_enemy_pos(enemy, enemy->x, enemy->y + step_y);
	else if (step_x && dy && is_valid_move(game, enemy->x, enemy->y + ((dy > 0)
				- (dy < 0))))
		update_enemy_pos(enemy, enemy->x, enemy->y + ((dy > 0) - (dy < 0)));
	else if (dx && is_valid_move(game, enemy->x + ((dx > 0) - (dx < 0)),
			enemy->y))
		update_enemy_pos(enemy, enemy->x + ((dx > 0) - (dx < 0)), enemy->y);
	if (enemy->x == game->map.p_x && enemy->y == game->map.p_y)
		handle_player_collision(game);
}

void	move_enemies(t_game *game)
{
	int	i;

	game->enemy_move_timer++;
	if (game->enemy_move_timer < 40)
		return ;
	game->enemy_move_timer = 0;
	if (game->game_state != STATE_PLAY)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		chase_player(game, &game->enemies[i]);
		i++;
	}
}
