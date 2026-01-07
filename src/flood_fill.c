/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:42:16 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!copy)
	{
		return (NULL);
	}
	i = 0;
	while (i < game->map.rows)
	{
		copy[i] = ft_strdup(game->map.full[i]);
		if (!copy[i])
		{
			free_map_copy(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood(char **map, int x, int y, t_map *info)
{
	char	tile;

	if (x < 0 || y < 0 || y >= info->rows || x >= info->cols)
		return ;
	tile = map[y][x];
	if (tile == '1' || tile == 'F' || tile == 'E')
		return ;
	if (tile == 'C')
		info->coins--;
	map[y][x] = 'F';
	flood(map, x + 1, y, info);
	flood(map, x - 1, y, info);
	flood(map, x, y + 1, info);
	flood(map, x, y - 1, info);
}

static int	check_neighbors(char **map, t_game *game, int x, int y)
{
	if (x > 0 && map[y][x - 1] == 'F')
		return (1);
	if (x < game->map.cols - 1 && map[y][x + 1] == 'F')
		return (1);
	if (y > 0 && map[y - 1][x] == 'F')
		return (1);
	if (y < game->map.rows - 1 && map[y + 1][x] == 'F')
		return (1);
	return (0);
}

static int	is_exit_reachable(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.full[y][x] == 'E')
			{
				if (check_neighbors(map, game, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_path(t_game *game)
{
	char	**temp_map;
	t_map	temp_info;

	temp_info = game->map;
	temp_map = copy_map(game);
	if (!temp_map)
		return (0);
	flood(temp_map, game->map.p_x, game->map.p_y, &temp_info);
	if (temp_info.coins != 0 || !is_exit_reachable(temp_map, game))
	{
		free_map_copy(temp_map, game->map.rows);
		ft_putstr_fd("Error\nInvalid Path: Cannot reach all coins or exit\n",
			2);
		return (0);
	}
	free_map_copy(temp_map, game->map.rows);
	return (1);
}
