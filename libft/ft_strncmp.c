/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:41:02 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:41:02 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>


// Helper to normalize the return value to -1, 0,
	or 1 for consistent comparison
int	normalize_cmp(int n)
{
	if (n > 0) return (1);
	if (n < 0) return (-1);
	return (0);
}

void	run_test(const char *s1, const char *s2, size_t n)
{
	printf("--- Comparing \"%s\" and \"%s\" (n=%zu) ---\n", s1, s2, n);

	int res_ft = ft_strncmp(s1, s2, n);
	int res_std = strncmp(s1, s2, n);

	printf("ft_strncmp: %d\n", normalize_cmp(res_ft));
	printf("strncmp:    %d\n", normalize_cmp(res_std));

	if (normalize_cmp(res_ft) == normalize_cmp(res_std))
		printf("Result: ✅ SUCCESS\n\n");
	else
		printf("Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	printf("--- Comparing ft_strncmp against system strncmp ---\n\n");
	run_test("abcdef", "abc\xffef", 6); // Test with non-ASCII char
	run_test("abcdef", "abcdef", 10);  // Test identical strings
	run_test("abcdef", "abc", 3);       // Test partial identical
	run_test("abcdef", "abc", 4);       // Test one char difference after match
	run_test("test", "testing", 4);    // Test identical prefix
	run_test("test", "test", 0);        // Test n=0
	return (0);
}
*/
