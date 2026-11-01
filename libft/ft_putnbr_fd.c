/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:34:24 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:34:25 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}

/*
#include <stdio.h>

int	main(void)
{
	// Test ft_putnbr_fd
	printf("Testing ft_putnbr_fd:\n");
	ft_putnbr_fd(12345, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-67890, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	printf("(Expected: 12345, -67890, and 0 on separate lines)\n");
	return (0);
}
*/