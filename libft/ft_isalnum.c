/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:28:34 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:28:34 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

/*
#include <stdio.h>


int	main(void)
{
	printf("--- Testing ft_isalnum ---\n");
	printf("'a': %d (Expected: 1)\n", ft_isalnum('a'));
	printf("'Z': %d (Expected: 1)\n", ft_isalnum('Z'));
	printf("'5': %d (Expected: 1)\n", ft_isalnum('5'));
	printf("'$': %d (Expected: 0)\n", ft_isalnum('$'));
	printf("Space: %d (Expected: 0)\n", ft_isalnum(' '));
	return (0);
}
*/