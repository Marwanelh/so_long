/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:40:23 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:40:23 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>


int	main(void)
{
	const char *test_strings[] = {"hello", "", "a very long string for testing",
		NULL};
	int i = 0;
	int success = 1;

	printf("--- Comparing ft_strlen against system strlen ---\n\n");

	while (test_strings[i])
	{
		size_t res_ft = ft_strlen(test_strings[i]);
		size_t res_std = strlen(test_strings[i]);

		printf("Testing with: \"%s\"\n", test_strings[i]);
		printf("ft_strlen: %zu\n", res_ft);
		printf("strlen:    %zu\n", res_std);

		if (res_ft != res_std)
		{
			printf("Result: ❌ FAILURE\n");
			success = 0;
		}
		else
		{
			printf("Result: ✅ SUCCESS\n");
		}
		printf("----------------------------------\n");
		i++;
	}

	if (success)
		printf("\nAll ft_strlen tests passed!\n");
	else
		printf("\nSome ft_strlen tests failed.\n");

	return (0);
}
*/
