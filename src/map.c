/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 03:46:05 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] && string[width] != '\n' && string[width] != '\r')
	{
		width++;
	}
	return (width);
}

static void	remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\r')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map.rows++;
	temporary = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
	if (!temporary)
		return (0);
	temporary[game->map.rows] = NULL;
	while (i < game->map.rows - 1)
	{
		temporary[i] = game->map.full[i];
		i++;
	}
	temporary[i] = line;
	if (game->map.full)
		free(game->map.full);
	game->map.full = temporary;
	return (1);
}

static int	process_line(t_game *game, char *line)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (1);
	}
	if (!add_line(game, line))
	{
		free(line);
		return (0);
	}
	return (1);
}

int	map_reading(t_game *game, char **argv)
{
	char	*line;
	int		result;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		remove_newline(line);
		result = process_line(game, line);
		if (result == 0)
			break ;
	}
	close(game->fd);
	if (game->map.full == NULL)
		return (0);
	game->map.cols = width_of_map(game->map.full[0]);
	return (1);
}
