/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 01:50:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:30:22 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_rect(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map.full[0]);
	while (i < game->map.rows)
	{
		if (ft_strlen(game->map.full[i]) != len)
		{
			return (0);
		}
		i++;
	}
	game->map.cols = len;
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.cols)
	{
		if (game->map.full[0][i] != '1' ||
		game->map.full[game->map.rows - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != '1' ||
		game->map.full[i][game->map.cols - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
