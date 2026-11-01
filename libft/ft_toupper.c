/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:43:06 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:43:06 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>


void	test_toupper(int c)
{
	int ft_res = ft_toupper(c);
	int std_res = toupper(c);
	printf("Input: '%c' (%d)\n", c, c);
	printf("  ft_toupper:  '%c' (%d)\n", ft_res, ft_res);
	printf("  std toupper: '%c' (%d)\n", std_res, std_res);
	if (ft_res == std_res)
		printf("  Result: ✅ SUCCESS\n\n");
	else
		printf("  Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	printf("--- Comparing ft_toupper against system toupper ---\n\n");
	test_toupper('a');
	test_toupper('z');
	test_toupper('G');
	test_toupper('5');
	test_toupper('$');
	return (0);
}
*/