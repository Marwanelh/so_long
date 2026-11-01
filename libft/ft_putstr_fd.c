/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:34:40 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:34:42 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}

/*
#include <stdio.h>

int	main(void)
{
	// Test ft_putstr_fd
	printf("Testing ft_putstr_fd:\n");
	ft_putstr_fd("Hello World!", 1);
	ft_putchar_fd('\n', 1);
	printf("(Expected: Hello World! followed by a newline)\n\n");
	return (0);
}
*/