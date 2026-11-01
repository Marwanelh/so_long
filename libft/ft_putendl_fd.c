/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:34:00 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:34:07 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

/*
void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		write(fd, s++, 1);
		write(fd, '\n', 1);
	}
}
*/

/*
#include <stdio.h>

int	main(void)
{
	// Test ft_putendl_fd
	printf("Testing ft_putendl_fd:\n");
	ft_putendl_fd("This should have a newline.", 1);
	printf("(Expected: The previous line should have a newline)\n\n");
	return (0);
}
*/