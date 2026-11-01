/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:39:09 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:39:09 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

/*
#include <bsd/string.h> // For strlcat on Linux/42 VMs
#include <stdio.h>
#include <string.h>


size_t	ft_strlen(const char *s) { size_t i = 0; while (s[i]) i++; return (i); }

void	run_test(const char *initial_dst, const char *src, size_t size)
{
	char    dst_ft[50];
	char    dst_std[50];
	size_t  ret_ft;
	size_t  ret_std;

	strcpy(dst_ft, initial_dst);
	strcpy(dst_std, initial_dst);

	printf("--- Testing dst=\"%s\", src=\"%s\", size=%zu ---\n", initial_dst,
		src, size);

	ret_ft = ft_strlcat(dst_ft, src, size);
	ret_std = strlcat(dst_std, src, size);

	printf("ft_strlcat: ret=%zu, dst=\"%s\"\n", ret_ft, dst_ft);
	printf("strlcat:    ret=%zu, dst=\"%s\"\n", ret_std, dst_std);

	if (ret_ft == ret_std && strcmp(dst_ft, dst_std) == 0)
		printf("Result: ✅ SUCCESS\n\n");
	else
		printf("Result: ❌ FAILURE\n\n");
}

int	main(void)
{
	printf("--- Comparing ft_strlcat against system strlcat ---\n\n");
	run_test("Hello", " World", 12);
	run_test("Hello", " World", 8);
	run_test("A long initial string", "appended", 20);
	run_test("test", "cat", 0);
	return (0);
}
*/
