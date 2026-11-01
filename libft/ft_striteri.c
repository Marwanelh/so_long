/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:28:56 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 15:29:05 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, s + i);
		++i;
	}
}

/*
#include <stdio.h>
#include <string.h>

// Test function: change char to 'a' + index
void	iterator_func(unsigned int i, char *c)
{
	*c = 'a' + i;
}

int	main(void)
{
	char	s1[] = "xxxxx";
	char	s2[] = "";

	printf("--- Testing ft_striteri ---\n");
	printf("Before: \"%s\"\n", s1);
	ft_striteri(s1, &iterator_func);
	printf("After:  \"%s\" (Expected: \"abcde\") -> %s\n", s1, strcmp(s1,
			"abcde") == 0 ? "✅" : "❌");
	printf("\nBefore: \"%s\"\n", s2);
	ft_striteri(s2, &iterator_func);
	printf("After:  \"%s\" (Expected: \"\") -> %s\n", s2, strcmp(s2,
			"") == 0 ? "✅" : "❌");
	return (0);
}
*/
