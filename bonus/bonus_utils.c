/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 02:55:00 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/09 02:55:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	reset_coins(t_game *game)
{
	size_t			i;
	int				frame;
	int				x;
	int				y;
	mlx_instance_t	*inst;

	i = 0;
	while (i < game->coin_frames[0]->count)
	{
		inst = &game->coin_frames[0]->instances[i];
		x = inst->x / 32;
		y = inst->y / 32;
		game->map.full[y][x] = 'C';
		frame = 0;
		while (frame < 4)
		{
			inst = &game->coin_frames[frame]->instances[i];
			inst->enabled = (frame == game->anim.frame);
			frame++;
		}
		i++;
	}
	game->map.coins = game->coin_frames[0]->count;
}

static void	reset_key_instance(t_game *game, int frame)
{
	int				x;
	int				y;
	mlx_instance_t	*inst;
	size_t			i;

	i = 0;
	while (i < game->key_frames[frame]->count)
	{
		inst = &game->key_frames[frame]->instances[i];
		x = inst->x / 32;
		y = inst->y / 32;
		game->map.full[y][x] = 'K';
		inst->enabled = (frame == game->anim.frame);
		i++;
	}
}

void	reset_key(t_game *game)
{
	int	frame;

	if (!game->has_key)
		return ;
	game->has_key = 0;
	frame = 0;
	while (frame < 4)
	{
		reset_key_instance(game, frame);
		frame++;
	}
}

void	handle_exit(t_game *game)
{
	if (game->map.coins == 0 && game->has_key == 1)
	{
		ft_putstr_fd("You escaped!\n", 1);
		mlx_close_window(game->mlx);
		return ;
	}
	ft_putstr_fd("Need all coins and the key!\n", 1);
}
