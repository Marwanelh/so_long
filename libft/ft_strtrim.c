/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:42:23 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:42:25 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stubs for dependencies
size_t	ft_strlen(const char *s) { size_t i = 0; while (s[i]) i++; return (i); }
char	*ft_strchr(const char *s, int c) {
	while (*s != (char)c) { if (*s == '\0') return (NULL); s++; }
	return ((char *)s);
}
char	*ft_strdup(const char *s) {
	size_t len = ft_strlen(s) + 1;
	char *dup = malloc(len);
	if(dup) memcpy(dup, s, len);
	return (dup);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size) {
	size_t i = 0;
	if (size > 0) {
		while (src[i] && i < (size - 1)) { dst[i] = src[i]; i++; }
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
char	*ft_substr(char const *s, unsigned int start, size_t len) {
	if (!s) return (NULL);
	size_t s_len = ft_strlen(s);
	if (start >= s_len) return (ft_strdup(""));
	if (len > s_len - start) len = s_len - start;
	char *sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub) return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}


int	main(void)
{
	char	*res;

	printf("--- Testing ft_strtrim ---\n");
	res = ft_strtrim("  ..Hello World.. ", " .");
	printf("Trimming \"  ..Hello World.. \" with \" .\": \"%s\" -> %s\n", res,
		strcmp(res, "Hello World") == 0 ? "✅" : "❌");
	free(res);
	res = ft_strtrim("NoTrim", "xyz");
	printf("Trimming \"NoTrim\" with \"xyz\": \"%s\" -> %s\n", res, strcmp(res,
			"NoTrim") == 0 ? "✅" : "❌");
	free(res);
	res = ft_strtrim("ababHelloabab", "ab");
	printf("Trimming \"ababHelloabab\" with \"ab\": \"%s\" -> %s\n", res,
		strcmp(res, "Hello") == 0 ? "✅" : "❌");
	free(res);
	res = ft_strtrim("Hello", "Hello");
	printf("Trimming \"Hello\" with \"Hello\": \"%s\" -> %s\n", res, strcmp(res,
			"") == 0 ? "✅" : "❌");
	free(res);
	return (0);
}
*/