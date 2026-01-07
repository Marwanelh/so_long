/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:38:07 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:38:07 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*
#include <stdio.h>
#include <string.h>


void	run_test(const char *s, int c)
{
	printf("--- Searching for '%c' in \"%s\" ---\n", (char)c, s);

	char *res_ft = ft_strchr(s, c);
	char *res_std = strchr(s, c);

	printf("ft_strchr result:  %s\n", res_ft ? res_ft : "NULL");
	printf("strchr result:     %s\n", res_std ? res_std : "NULL");

	if (res_ft == res_std)
		printf("Result: ✅ SUCCESS\n\n");
	else
		printf("Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	printf("--- Comparing ft_strchr against system strchr ---\n\n");
	run_test("hello world", 'w');
	run_test("hello world", 'z');
	run_test("hello world", '\0');
	return (0);
}
*/