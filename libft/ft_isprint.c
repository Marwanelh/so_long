/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:29:45 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:29:45 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <stdio.h>


int	main(void)
{
	printf("--- Testing ft_isprint ---\n");
	printf("'a': %d (Expected: 1)\n", ft_isprint('a'));
	printf("' ': %d (Expected: 1)\n", ft_isprint(' ')); // Space is printable
	printf("126 (~): %d (Expected: 1)\n", ft_isprint(126));
	printf("31 (US): %d (Expected: 0)\n", ft_isprint(31));
		// Unit Separator is not
	printf("127 (DEL): %d (Expected: 0)\n", ft_isprint(127));
	return (0);
}
*/