/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:33:47 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:33:48 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <stdio.h>

int	main(void)
{
	// Test ft_putchar_fd
	printf("Testing ft_putchar_fd:\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	printf("(Expected: A followed by a newline)\n\n");
	return (0);
}
*/