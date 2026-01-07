/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 01:50:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:40:35 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render_frames(t_game *game, mlx_image_t **frames, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		img_to_win(game, frames[i], x, y);
		frames[i]->instances[frames[i]->count - 1].enabled = (i == 0);
		i++;
	}
}

void	render_entities(t_game *game, int y, int x)
{
	if (game->map.full[y][x] == 'C')
	{
		render_frames(game, game->coin_frames, x, y);
	}
	else if (game->map.full[y][x] == 'K')
	{
		render_frames(game, game->key_frames, x, y);
	}
	else if (game->map.full[y][x] == 'E')
	{
		img_to_win(game, game->door, x, y);
	}
}
