/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:27:49 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:27:49 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	bytes = nmemb * size;
	if (bytes / size != nmemb)
		return (NULL);
	ptr = (void *)malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Stubs for dependencies
void	*ft_memset(void *b, int c, size_t len) {
	unsigned char *p = b;
	while(len-- > 0) *p++ = (unsigned char)c;
	return (b);
}
void	ft_bzero(void *s, size_t n) { ft_memset(s, 0, n); }

void	run_test(size_t nmemb, size_t size)
{
	printf("--- Testing nmemb=%zu, size=%zu ---\n", nmemb, size);

	void *ptr_ft = ft_calloc(nmemb, size);
	void *ptr_std = calloc(nmemb, size);

	if (nmemb == 0 || size == 0)
	{
		printf("ft_calloc:  %s\n",
			ptr_ft ? "Returned valid pointer" : "Returned NULL");
		printf("calloc:     %s\n",
			ptr_std ? "Returned valid pointer" : "Returned NULL");
		if (ptr_ft && ptr_std) printf("Result: ✅ SUCCESS\n\n");
		else printf("Result: ❌ FAILURE\n\n");
	}
	else
	{
		size_t total_size = nmemb * size;
		int cmp_res = memcmp(ptr_ft, ptr_std, total_size);
		printf("ft_calloc and calloc memory blocks are %s\n",
			cmp_res == 0 ? "identical." : "different.");
		if (cmp_res == 0) printf("Result: ✅ SUCCESS\n\n");
		else printf("Result: ❌ FAILURE\n\n");
	}
	free(ptr_ft);
	free(ptr_std);
}

int	main(void)
{
	printf("--- Comparing ft_calloc against system calloc ---\n\n");
	run_test(10, sizeof(char));
	run_test(5, sizeof(int));
	run_test(0, 10);
	run_test(10, 0);
	return (0);
}
*/