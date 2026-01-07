/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:30:31 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:30:31 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>


int	main(void)
{
	const char *s = "This is a test string for memchr.";
	int c = 't';
	size_t n = strlen(s);

	printf("--- Comparing ft_memchr against system memchr ---\n\n");
	printf("Searching for '%c' in \"%s\"\n", c, s);

	char *res_ft = ft_memchr(s, c, n);
	char *res_std = memchr(s, c, n);

	printf("ft_memchr result:  %s\n", res_ft ? res_ft : "NULL");
	printf("memchr result:     %s\n", res_std ? res_std : "NULL");

	if (res_ft == res_std)
		printf("Result: ✅ SUCCESS\n");
	else
		printf("Result: ❌ FAILURE\n");

	printf("\n--- Searching for a character not present ('z') ---\n");
	res_ft = ft_memchr(s, 'z', n);
	res_std = memchr(s, 'z', n);

	printf("ft_memchr result:  %s\n", res_ft ? res_ft : "NULL");
	printf("memchr result:     %s\n", res_std ? res_std : "NULL");

	if (res_ft == res_std)
		printf("Result: ✅ SUCCESS\n");
	else
		printf("Result: ❌ FAILURE\n");

	return (0);
}
*/
