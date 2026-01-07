/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 02:55:00 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/09 02:55:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	render_floor(t_game *game)
{
	int	y;
	int	x;
	int	frame;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			frame = (x + y) % 4;
			img_to_win(game, game->floor_frames[frame], x, y);
			x++;
		}
		y++;
	}
}

static void	render_walls_and_objects(t_game *game)
{
	int	y;
	int	x;
	int	frame;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.full[y][x] == '1')
			{
				frame = (x + y) % 4;
				img_to_win(game, game->wall_frames[frame], x, y);
			}
			else
				render_entities(game, y, x);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	int				i;
	size_t			count;
	mlx_instance_t	*inst;

	render_floor(game);
	render_walls_and_objects(game);
	init_enemies(game);
	i = 0;
	while (i < 4)
	{
		img_to_win(game, game->player_frames[i], game->map.p_x, game->map.p_y);
		count = game->player_frames[i]->count;
		inst = &game->player_frames[i]->instances[count - 1];
		inst->enabled = (i == 0);
		i++;
	}
	init_menus(game);
	toggle_menus(game);
}
