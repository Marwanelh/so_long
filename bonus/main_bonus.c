/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/14 22:37:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	free_map(t_game *game)
{
	int	i;

	if (!game->map.full)
	{
		return ;
	}
	i = 0;
	while (i < game->map.rows)
	{
		free(game->map.full[i]);
		i++;
	}
	free(game->map.full);
}

static void	cleanup_game(t_game *game)
{
	free_map(game);
	if (game->enemies)
		free(game->enemies);
	if (game->music_pid > 0)
		kill(game->music_pid, SIGTERM);
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
	}
}

static void	setup_game_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_close_hook(game->mlx, &my_closehook, game);
	mlx_loop_hook(game->mlx, &update_animations, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_and_exit("Usage: ./so_long <map.ber>");
	ft_bzero(&game, sizeof(t_game));
	if (!map_reading(&game, argv))
		ft_error_and_exit("Failed to read map");
	if (!check_map(&game))
	{
		free_map(&game);
		ft_error_and_exit("Map validation failed");
	}
	init_game(&game);
	game.spawn_x = game.map.p_x;
	game.spawn_y = game.map.p_y;
	render_map(&game);
	setup_game_hooks(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (EXIT_SUCCESS);
}
