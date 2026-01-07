/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:37:44 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 17:46:51 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**free_all(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**fill_words(char const *s, char c, char **res_arr)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			res_arr[i] = ft_substr(s - len, 0, len);
			if (!res_arr[i])
				return (free_all(res_arr));
			i++;
		}
		else
			s++;
	}
	res_arr[i] = NULL;
	return (res_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**res_arr;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = get_word_count(s, c);
	res_arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res_arr)
		return (NULL);
	return (fill_words(s, c, res_arr));
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Stubs for dependencies ---
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
// --- End of Stubs ---

// Helper to free the array returned by ft_split
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(void)
{
	char	**result;

	printf("--- Testing ft_split ---\n\n");
	printf("1. Splitting \"hello world test\" by ' ':\n");
	result = ft_split("hello world test", ' ');
	// Expected: ["hello", "world", "test", NULL]
	if (result && strcmp(result[0], "hello") == 0 && strcmp(result[1],
			"world") == 0 && strcmp(result[2], "test") == 0
		&& result[3] == NULL)
		printf("   Result: ✅ SUCCESS\n\n");
	elsestatic size_t	get_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**free_all(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res_arr;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	res_arr = (char **)malloc(sizeof(char *) * (get_word_count(s, c) + 1));
	if (!res_arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			res_arr[i] = ft_substr(s - len, 0, len);
			if (!res_arr[i])
				return (free_all(res_arr));
			i++;
		}
		else
			s++;
	}
	res_arr[i] = NULL;
	return (res_arr);
}
		printf("   Result: ❌ FAILURE\n\n");
	free_split(result);
	printf("2. Splitting \"---split---this---\" by '-':\n");
	result = ft_split("---split---this---", '-');
	// Expected: ["split", "this", NULL]
	if (result && strcmp(result[0], "split") == 0 && strcmp(result[1],
			"this") == 0 && result[2] == NULL)
		printf("   Result: ✅ SUCCESS\n\n");
	else
		printf("   Result: ❌ FAILURE\n\n");
	free_split(result);
	printf("3. Splitting an empty string \"\" by 'x':\n");
	result = ft_split("", 'x');
	// Expected: [NULL]
	if (result && result[0] == NULL)
		printf("   Result: ✅ SUCCESS\n\n");
	else
		printf("   Result: ❌ FAILURE\n\n");
	free_split(result);
	return (0);
}
*/
