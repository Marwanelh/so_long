/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:42:52 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:42:52 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t	ft_strlen(const char *s) { size_t i = 0; while (s[i]) i++; return (i); }
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


int	main(void)
{
	char *s = "Hello World";
	char *sub;

	printf("--- Testing ft_substr ---\n");

	sub = ft_substr(s, 6, 5);
	printf("Substring from index 6, len 5: \"%s\" (Expected: \"World\") ->
		%s\n", sub, strcmp(sub, "World") == 0 ? "✅" : "❌");
	free(sub);

	sub = ft_substr(s, 0, 5);
	printf("Substring from index 0, len 5: \"%s\" (Expected: \"Hello\") ->
		%s\n", sub, strcmp(sub, "Hello") == 0 ? "✅" : "❌");
	free(sub);

	sub = ft_substr(s, 20, 5);
	printf("Substring from out of bounds index: \"%s\" (Expected: \"\") ->
		%s\n", sub, strcmp(sub, "") == 0 ? "✅" : "❌");
	free(sub);

	sub = ft_substr(s, 6, 100);
		printf("Substring with oversized length: \"%s\" (Expected: \"World\") ->
			%s\n", sub, strcmp(sub, "World") == 0 ? "✅" : "❌");
	free(sub);

	return (0);
}
*/
