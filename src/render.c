/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/14 19:11:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		render_frames(game, game->coin_frames, x, y);
	else if (game->map.full[y][x] == 'E')
		img_to_win(game, game->door, x, y);
}

static void	render_floor(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			img_to_win(game, game->floor_frames[0], x, y);
			x++;
		}
		y++;
	}
}

static void	render_walls_and_objects(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.full[y][x] == '1')
				img_to_win(game, game->wall_frames[0], x, y);
			else
				render_entities(game, y, x);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	int	i;

	render_floor(game);
	render_walls_and_objects(game);
	i = 0;
	while (i < 4)
	{
		img_to_win(game, game->player_frames[i], game->map.p_x, game->map.p_y);
		game->player_frames[i]->instances[game->player_frames[i]->count
			- 1].enabled = (i == 0);
		i++;
	}
}
