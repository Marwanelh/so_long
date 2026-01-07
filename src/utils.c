/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/08 17:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_trim_cr(char *s)
{
	int	len;

	if (!s)
	{
		return ;
	}
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\r')
	{
		s[len - 1] = '\0';
	}
}

void	ft_error_and_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	img_to_win(t_game *game, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(game->mlx, img, x * 32, y * 32) < 0)
	{
		ft_error_and_exit("Image render failed");
	}
}
