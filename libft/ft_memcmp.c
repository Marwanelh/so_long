/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:31:04 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:31:04 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>


// Helper to normalize the return value to -1, 0, or 1
int	normalize_cmp(int n)
{
	if (n > 0) return (1);
	if (n < 0) return (-1);
	return (0);
}

int	main(void)
{
	printf("--- Comparing ft_memcmp against system memcmp ---\n\n");

	const char *s1 = "abcdef";
	const char *s2 = "abc\xffef";
	const char *s3 = "abcdef";

	// Test 1: Different strings
	int res_ft1 = ft_memcmp(s1, s2, 6);
	int res_std1 = memcmp(s1, s2, 6);
	printf("Test 1 (s1 vs s2):\n");
	printf("ft_memcmp:  %d\n", normalize_cmp(res_ft1));
	printf("memcmp:     %d\n", normalize_cmp(res_std1));
	if (normalize_cmp(res_ft1) == normalize_cmp(res_std1))
		printf("Result: ✅ SUCCESS\n");
	else
		printf("Result: ❌ FAILURE\n");

	// Test 2: Identical strings
	int res_ft2 = ft_memcmp(s1, s3, 6);
	int res_std2 = memcmp(s1, s3, 6);
	printf("\nTest 2 (s1 vs s3):\n");
	printf("ft_memcmp:  %d\n", normalize_cmp(res_ft2));
	printf("memcmp:     %d\n", normalize_cmp(res_std2));
	if (normalize_cmp(res_ft2) == normalize_cmp(res_std2))
		printf("Result: ✅ SUCCESS\n");
	else
		printf("Result: ❌ FAILURE\n");

	return (0);
}
*/
