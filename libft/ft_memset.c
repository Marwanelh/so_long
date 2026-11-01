/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:33:33 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:33:33 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
#include <string.h>


void	print_result(const char *label, const void *ptr, size_t size)
{
	const unsigned char *p = ptr;
	printf("%-15s: \"", label);
	for (size_t i = 0; i < size; i++)
	{
		if (p[i] >= 32 && p[i] <= 126)
			printf("%c", p[i]);
		else
			printf("\\%d", p[i]);
	}
	printf("\"\n");
}

int	main(void)
{
	char    buffer_ft[20];
	char    buffer_std[20];

	printf("--- Comparing ft_memset against system memset ---\n\n");

	printf("--- Test 1: Fill with 'A' ---\n");
	ft_memset(buffer_ft, 'A', 15);
	memset(buffer_std, 'A', 15);

	print_result("ft_memset", buffer_ft, 15);
	print_result("memset", buffer_std, 15);
	if (memcmp(buffer_ft, buffer_std, 15) == 0)
		printf("Result: ✅ SUCCESS\n");
	else
		printf("Result: ❌ FAILURE\n");

	printf("\n--- Test 2: Fill with zero ---\n");
	ft_memset(buffer_ft, 0, 20);
	memset(buffer_std, 0, 20);

	print_result("ft_memset", buffer_ft, 20);
	print_result("memset", buffer_std, 20);
	if (memcmp(buffer_ft, buffer_std, 20) == 0)
		printf("Result: ✅ SUCCESS\n");
	else
		printf("Result: ❌ FAILURE\n");

	return (0);
}
*/