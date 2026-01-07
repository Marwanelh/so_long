/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:38:21 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:38:21 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	buf_size;

	buf_size = ft_strlen(src) + 1;
	str = (char *)malloc(buf_size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, src, buf_size);
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t	ft_strlen(const char *s) { size_t i = 0; while (s[i]) i++; return (i); }
size_t	ft_strlcpy(char *dst, const char *src, size_t size) {
	size_t i = 0;
	if (size > 0) {
		while (src[i] && i < (size - 1)) { dst[i] = src[i]; i++; }
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	run_test(const char *src)
{
	printf("--- Testing with src=\"%s\" ---\n", src);

	char *dup_ft = ft_strdup(src);
	char *dup_std = strdup(src);

	printf("ft_strdup result: \"%s\"\n", dup_ft);
	printf("strdup result:    \"%s\"\n", dup_std);

	if (strcmp(dup_ft, dup_std) == 0)
		printf("Result: ✅ SUCCESS\n\n");
	else
		printf("Result: ❌ FAILURE\n\n");

	free(dup_ft);
	free(dup_std);
}

int	main(void)
{
	printf("--- Comparing ft_strdup against system strdup ---\n\n");
	run_test("Hello, World!");
	run_test("");
	run_test("a very long string to duplicate");
	return (0);
}
*/
