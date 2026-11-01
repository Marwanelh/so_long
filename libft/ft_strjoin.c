/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:38:57 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:38:57 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	return (new_str);
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
size_t	ft_strlcat(char *dst, const char *src, size_t size) {
	size_t dst_len = ft_strlen(dst);
	size_t src_len = ft_strlen(src);
	if (dst_len >= size) return (size + src_len);
	size_t i = 0;
	while (src[i] && (dst_len + i) < (size - 1)) {
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "World!";
	char *res;

	printf("--- Testing ft_strjoin ---\n");
	res = ft_strjoin(s1, s2);
	printf("Joining \"%s\" and \"%s\": \"%s\" -> %s\n", s1, s2, res, strcmp(res,
			"Hello, World!") == 0 ? "✅" : "❌");
	free(res);

	res = ft_strjoin("", "Test");
	printf("Joining \"\" and \"Test\": \"%s\" -> %s\n", res, strcmp(res,
			"Test") == 0 ? "✅" : "❌");
	free(res);

	res = ft_strjoin("Test", "");
	printf("Joining \"Test\" and \"\": \"%s\" -> %s\n", res, strcmp(res,
			"Test") == 0 ? "✅" : "❌");
	free(res);

	res = ft_strjoin("", "");
	printf("Joining \"\" and \"\": \"%s\" -> %s\n", res, strcmp(res,
			"") == 0 ? "✅" : "❌");
	free(res);

	return (0);
}
*/
