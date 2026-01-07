/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:29:08 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:29:08 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
#include <stdio.h>


int	main(void)
{
	printf("--- Testing ft_isalpha ---\n");
	printf("'a': %d (Expected: 1)\n", ft_isalpha('a'));
	printf("'Z': %d (Expected: 1)\n", ft_isalpha('Z'));
	printf("'5': %d (Expected: 0)\n", ft_isalpha('5'));
	printf("'$': %d (Expected: 0)\n", ft_isalpha('$'));
	printf("NULL (0): %d (Expected: 0)\n", ft_isalpha(0));
	return (0);
}
*/