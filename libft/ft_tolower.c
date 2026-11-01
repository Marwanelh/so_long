/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:40:36 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 15:40:36 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>


// Helper function to run a single test and print the result
void	test_tolower(int c)
{
	int ft_res = ft_tolower(c);
	int std_res = tolower(c);

	printf("Input: '%c' (%d)\n", c, c);
	printf("  ft_tolower:  '%c' (%d)\n", ft_res, ft_res);
	printf("  std tolower: '%c' (%d)\n", std_res, std_res);

	if (ft_res == std_res)
		printf("  Result: ✅ SUCCESS\n\n");
	else
		printf("  Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	printf("--- Comparing ft_tolower against system tolower ---\n\n");
	test_tolower('A');      // Test uppercase
	test_tolower('Z');      // Test uppercase boundary
	test_tolower('g');      // Test lowercase (should not change)
	test_tolower('5');      // Test digit
	test_tolower('$');      // Test symbol

	return (0);
}
*/
