/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:30:09 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_chars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (!ft_strchr("01CEP T M K", game->map.full[y][x]))
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static void	count_checker(t_game *game, int y, int x)
{
	if (game->map.full[y][x] == 'P')
	{
		game->map.p_x = x;
		game->map.p_y = y;
		game->map.players++;
	}
	if (game->map.full[y][x] == 'E')
		game->map.exit++;
	if (game->map.full[y][x] == 'C')
		game->map.coins++;
	if (game->map.full[y][x] == 'M')
		game->map.monsters++;
}

static int	validate_counts(t_game *game)
{
	if (!check_rect(game) || !check_walls(game) || !check_chars(game))
	{
		ft_putstr_fd("Error\nMap error\n", 2);
		return (0);
	}
	if (game->map.players != 1 || game->map.exit != 1 || game->map.coins < 1)
	{
		ft_putstr_fd("Error\nInvalid map config\n", 2);
		return (0);
	}
	return (1);
}

int	check_map(t_game *game)
{
	int	x;
	int	y;

	game->map.players = 0;
	game->map.exit = 0;
	game->map.coins = 0;
	game->map.monsters = 0;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			count_checker(game, y, x);
			x++;
		}
		y++;
	}
	if (!validate_counts(game))
		return (0);
	if (!check_path(game))
		return (0);
	return (1);
}
