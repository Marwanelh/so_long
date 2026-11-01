/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:29:29 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:29:29 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include <stdio.h>


int	main(void)
{
	printf("--- Testing ft_isdigit ---\n");
	printf("'7': %d (Expected: 1)\n", ft_isdigit('7'));
	printf("'0': %d (Expected: 1)\n", ft_isdigit('0'));
	printf("'a': %d (Expected: 0)\n", ft_isdigit('a'));
	printf("'$': %d (Expected: 0)\n", ft_isdigit('$'));
	return (0);
}
*/