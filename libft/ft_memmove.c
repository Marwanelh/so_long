/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:32:57 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:32:57 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
			*((char *)dst + len) = *((char *)src + len);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h> // For the real memmove, strcpy, and memcmp


// A helper function to print the buffer and add a newline
void	print_buffer(const char *label, const char *buffer)
{
	printf("%-18s: \"%s\"\n", label, buffer);
}

int	main(void)
{
	char    buffer_ft[30];
	char    buffer_std[30];
	int     test_ok;

	printf("--- Comparing ft_memmove against system memmove ---\n\n");

	// --- TEST 1: Backward copy (dst > src) ---
	printf("--- Test 1: Backward Copy (dst > src) ---\n");
	strcpy(buffer_ft, "abcdefghijklmnopqrstuvwxyz");
	strcpy(buffer_std, "abcdefghijklmnopqrstuvwxyz");

	print_buffer("Before (ft)", buffer_ft);
	print_buffer("Before (std)", buffer_std);
	printf("\n");

	ft_memmove(buffer_ft + 2, buffer_ft, 5);
	memmove(buffer_std + 2, buffer_std, 5);

	print_buffer("After (ft)", buffer_ft);
	print_buffer("After (std)", buffer_std);

	test_ok = (memcmp(buffer_ft, buffer_std, 30) == 0);
	if (test_ok)
	printf("Result: ✅ SUCCESS\n");
	else
	printf("Result: ❌ FAILURE\n");

printf("\n---------------------------------------------\n\n");

// --- TEST 2: Forward copy (src > dst) ---
printf("--- Test 2: Forward Copy (src > dst) ---\n");
strcpy(buffer_ft, "abcdefghijklmnopqrstuvwxyz");
strcpy(buffer_std, "abcdefghijklmnopqrstuvwxyz");

print_buffer("Before (ft)", buffer_ft);
print_buffer("Before (std)", buffer_std);
printf("\n");

ft_memmove(buffer_ft, buffer_ft + 2, 5);
memmove(buffer_std, buffer_std + 2, 5);

print_buffer("After (ft)", buffer_ft);
print_buffer("After (std)", buffer_std);

test_ok = (memcmp(buffer_ft, buffer_std, 30) == 0);
if (test_ok)
printf("Result: ✅ SUCCESS\n");
else
printf("Result: ❌ FAILURE\n");

return (0);
}
*/