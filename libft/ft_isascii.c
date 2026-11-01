/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:29:13 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:29:13 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}

/*
#include <stdio.h>


int	main(void)
{
	printf("--- Testing ft_isascii ---\n");
	printf("'a': %d (Expected: 1)\n", ft_isascii('a'));
	printf("127 (DEL): %d (Expected: 0)\n", ft_isascii(127));
	printf("0 (NULL): %d (Expected: 1)\n", ft_isascii(0));
	printf("128: %d (Expected: 0)\n", ft_isascii(128));
	return (0);
}
*/