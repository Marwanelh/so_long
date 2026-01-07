/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:41:48 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != '1' || game->map.full[i][game->map.cols
			- 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.cols)
	{
		if (game->map.full[0][i] != '1' || game->map.full[game->map.rows
			- 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	count_checker(t_game *game, int height, int width)
{
	char	c;

	c = game->map.full[height][width];
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_putstr_fd("Error\nInvalid character in map\n", 2);
		return (0);
	}
	if (c == 'C')
		game->map.coins++;
	if (c == 'P')
	{
		game->map.players++;
		game->map.p_x = width;
		game->map.p_y = height;
	}
	if (c == 'E')
		game->map.exit++;
	return (1);
}

static int	validate_map_tiles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		if ((int)ft_strlen(game->map.full[i]) != game->map.cols)
		{
			ft_putstr_fd("Error\nMap is not rectangular\n", 2);
			return (0);
		}
		while (j < game->map.cols)
		{
			if (!count_checker(game, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	if (!validate_map_tiles(game))
		return (0);
	if (!check_walls(game))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (0);
	}
	if (game->map.coins < 1 || game->map.exit != 1 || game->map.players != 1)
	{
		ft_putstr_fd("Error\nInvalid map configuration\n", 2);
		return (0);
	}
	if (!check_path(game))
		return (0);
	return (1);
}
