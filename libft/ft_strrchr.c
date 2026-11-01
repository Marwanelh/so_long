/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:41:59 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:41:59 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
		{
			return ((char *)(s + len));
		}
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>


size_t	ft_strlen(const char *s) { size_t i = 0; while (s[i]) i++; return (i); }

void	run_test(const char *s, int c)
{
	printf("--- Searching for last '%c' in \"%s\" ---\n", (char)c, s);

	char *res_ft = ft_strrchr(s, c);
	char *res_std = strrchr(s, c);

	printf("ft_strrchr result:  %s\n", res_ft ? res_ft : "NULL");
	printf("strrchr result:     %s\n", res_std ? res_std : "NULL");

	if (res_ft == res_std)
		printf("Result: ✅ SUCCESS\n\n");
	else
		printf("Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	printf("--- Comparing ft_strrchr against system strrchr ---\n\n");
	run_test("hello world hello", 'h');
	run_test("hello world hello", 'l');
	run_test("hello world hello", 'z');
	run_test("hello world", '\0');
	return (0);
}
*/