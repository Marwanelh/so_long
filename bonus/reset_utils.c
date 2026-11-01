/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:00:00 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/14 23:00:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_move_display(t_game *game)
{
	char	*str;
	char	*num;

	if (game->move_display)
		mlx_delete_image(game->mlx, game->move_display);
	num = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", num);
	game->move_display = mlx_put_string(game->mlx, str, 10, 10);
	free(num);
	free(str);
}
