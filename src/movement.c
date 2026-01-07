/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/14 20:03:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_exit(t_game *game)
{
	if (game->map.coins == 0)
	{
		ft_putstr_fd("You escaped!\n", 1);
		mlx_close_window(game->mlx);
		return ;
	}
	ft_putstr_fd("Collect all coins to exit!\n", 1);
}

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
}

void	move_player(t_game *game, int next_y, int next_x)
{
	char	tile;

	if (game->move_timer > 0)
		return ;
	tile = game->map.full[next_y][next_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
	{
		game->map.coins--;
		game->map.full[next_y][next_x] = '0';
		ft_putstr_fd("Coin collected!\n", 1);
	}
	process_move(game, next_y, next_x);
	if (tile == 'E')
		handle_exit(game);
}
