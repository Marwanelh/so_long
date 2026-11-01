/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:41:32 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:41:32 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <bsd/string.h> // For strnstr on Linux/42 VMs
#include <stdio.h>
#include <string.h>


void	run_test(const char *haystack, const char *needle, size_t len)
{
	printf("--- Searching for \"%s\" in \"%s\" (len=%zu) ---\n", needle,
		haystack, len);

	char *res_ft = ft_strnstr(haystack, needle, len);
	char *res_std = strnstr(haystack, needle, len);

	printf("ft_strnstr result:  %s\n", res_ft ? res_ft : "NULL");
	printf("strnstr result:     %s\n", res_std ? res_std : "NULL");

	if (res_ft == res_std)
		printf("Result: ✅ SUCCESS\n\n");
	else
		printf("Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	const char *haystack = "lorem ipsum dolor sit amet";

	printf("--- Comparing ft_strnstr against system strnstr ---\n\n");
	run_test(haystack, "ipsum", 15);
	run_test(haystack, "dolor", 15); // Should not be found
	run_test(haystack, "dolor", 20); // Should be found
	run_test(haystack, "lorem", 0);  // Should not be found
	run_test(haystack, "", 10);      // Empty needle is always found
	run_test("ababab", "bab", 5);
	return (0);
}
*/