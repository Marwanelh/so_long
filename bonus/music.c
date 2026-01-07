/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/10 02:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	redirect_errors(void)
{
	int	fd;

	fd = open("/dev/null", O_WRONLY);
	if (fd != -1)
	{
		dup2(fd, STDERR_FILENO);
		close(fd);
	}
}

void	init_music(t_game *game)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		redirect_errors();
		execlp("cvlc", "cvlc", "--play-and-exit", "--no-video",
			"sound/music.mp3", NULL);
		execlp("ffplay", "ffplay", "-nodisp", "-autoexit", "-loglevel", "quiet",
			"sound/music.mp3", NULL);
		execlp("mpv", "mpv", "--no-video", "--quiet", "sound/music.mp3", NULL);
		execlp("paplay", "paplay", "--volume=65536", "sound/music.mp3", NULL);
		execlp("aplay", "aplay", "-q", "sound/music.mp3", NULL);
		exit(0);
	}
	else if (pid > 0)
	{
		game->music_pid = pid;
	}
}
