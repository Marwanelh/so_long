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

void	init_music(t_game *game)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execlp("paplay", "paplay", "--volume=65536", "sound/music.mp3", NULL);
		execlp("ffplay", "ffplay", "-nodisp", "-autoexit", "-loglevel", "quiet",
			"sound/music.mp3", NULL);
		execlp("mpv", "mpv", "--no-video", "--quiet", "sound/music.mp3", NULL);
		execlp("cvlc", "cvlc", "--play-and-exit", "--no-video",
			"sound/music.mp3", NULL);
		execlp("aplay", "aplay", "sound/music.mp3", NULL);
		exit(1);
	}
	else
	{
		game->music_pid = pid;
	}
}
