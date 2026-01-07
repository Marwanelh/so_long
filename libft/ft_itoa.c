/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:29:57 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:30:00 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	len = count_digits(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

/*
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*res;

	printf("--- Testing ft_itoa ---\n");
	res = ft_itoa(12345);
	printf("Number 12345: \"%s\" -> %s\n", res, strcmp(res,
			"12345") == 0 ? "✅" : "❌");
	free(res);
	res = ft_itoa(-9876);
	printf("Number -9876: \"%s\" -> %s\n", res, strcmp(res,
			"-9876") == 0 ? "✅" : "❌");
	free(res);
	res = ft_itoa(0);
	printf("Number 0: \"%s\" -> %s\n", res, strcmp(res, "0") == 0 ? "✅" : "❌");
	free(res);
	res = ft_itoa(INT_MAX);
	printf("Number INT_MAX: \"%s\" -> %s\n", res, strcmp(res,
			"2147483647") == 0 ? "✅" : "❌");
	free(res);
	res = ft_itoa(INT_MIN);
	printf("Number INT_MIN: \"%s\" -> %s\n", res, strcmp(res,
			"-2147483648") == 0 ? "✅" : "❌");
	free(res);
	return (0);
}
*/
