/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:31:21 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:31:21 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	if (dst != src)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>


int	main(void)
{
	char    src[] = "This is a test string.";
	char    dst_ft[30];
	char    dst_std[30];
	size_t  n = strlen(src) + 1;

	printf("--- Comparing ft_memcpy against system memcpy ---\n\n");

	ft_memcpy(dst_ft, src, n);
	memcpy(dst_std, src, n);

	printf("Source:           \"%s\"\n", src);
	printf("ft_memcpy result: \"%s\"\n", dst_ft);
	printf("memcpy result:    \"%s\"\n", dst_std);

	if (strcmp(dst_ft, dst_std) == 0)
		printf("Result: ✅ SUCCESS\n");
	else
		printf("Result: ❌ FAILURE\n");

	return (0);
}
*/