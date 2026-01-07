/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:39:26 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	process_move(t_game *game, int next_y, int next_x)
{
	int	i;

	game->move_timer = 5;
	i = 0;
	while (i < 4)
	{
		game->player_frames[i]->instances[0].x = next_x * 32;
		game->player_frames[i]->instances[0].y = next_y * 32;
		i++;
	}
	game->map.p_x = next_x;
	game->map.p_y = next_y;
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	update_move_display(game);
}

static void	disable_coin_instance(t_game *game, int x, int y)
{
	int		frame;
	size_t	i;

	frame = 0;
	while (frame < 4)
	{
		i = 0;
		while (i < game->coin_frames[frame]->count)
		{
			if (game->coin_frames[frame]->instances[i].x == x * 32
				&& game->coin_frames[frame]->instances[i].y == y * 32)
			{
				game->coin_frames[frame]->instances[i].enabled = false;
			}
			i++;
		}
		frame++;
	}
}

static void	disable_key_instance(t_game *game, int x, int y)
{
	int		frame;
	size_t	i;

	frame = 0;
	while (frame < 4)
	{
		i = 0;
		while (i < game->key_frames[frame]->count)
		{
			if (game->key_frames[frame]->instances[i].x == x * 32
				&& game->key_frames[frame]->instances[i].y == y * 32)
			{
				game->key_frames[frame]->instances[i].enabled = false;
			}
			i++;
		}
		frame++;
	}
}

static void	handle_collectibles(t_game *game, int next_y, int next_x)
{
	char	tile;

	tile = game->map.full[next_y][next_x];
	if (tile == 'C')
	{
		game->map.coins--;
		game->map.full[next_y][next_x] = '0';
		disable_coin_instance(game, next_x, next_y);
		ft_putstr_fd("Coin collected!\n", 1);
	}
	if (tile == 'K')
	{
		game->map.full[next_y][next_x] = '0';
		game->has_key = 1;
		disable_key_instance(game, next_x, next_y);
		ft_putstr_fd("Key collected!\n", 1);
	}
}

void	move_player(t_game *game, int next_y, int next_x)
{
	char	tile;

	if (game->move_timer > 0)
		return ;
	tile = game->map.full[next_y][next_x];
	if (tile == '1')
		return ;
	handle_collectibles(game, next_y, next_x);
	process_move(game, next_y, next_x);
	if (tile == 'E')
		handle_exit(game);
}
