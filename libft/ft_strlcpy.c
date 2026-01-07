/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:39:41 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:39:41 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <bsd/string.h> // For strlcpy on Linux/42 VMs
#include <stdio.h>
#include <string.h>


size_t	ft_strlen(const char *s) { size_t i = 0; while (s[i]) i++; return (i); }

void	run_test(const char *src, size_t size)
{
	char    dst_ft[50] = {0};
	char    dst_std[50] = {0};
	size_t  ret_ft;
	size_t  ret_std;

	printf("--- Testing with src=\"%s\", size=%zu ---\n", src, size);

	ret_ft = ft_strlcpy(dst_ft, src, size);
	ret_std = strlcpy(dst_std, src, size);

	printf("ft_strlcpy: ret=%zu, dst=\"%s\"\n", ret_ft, dst_ft);
	printf("strlcpy:    ret=%zu, dst=\"%s\"\n", ret_std, dst_std);

	if (ret_ft == ret_std && strcmp(dst_ft, dst_std) == 0)
		printf("Result: ✅ SUCCESS\n\n");
	else
		printf("Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	printf("--- Comparing ft_strlcpy against system strlcpy ---\n\n");
	run_test("hello world", 12);
	run_test("hello world", 5);
	run_test("short", 20);
	run_test("test", 0);
	return (0);
}
*/
