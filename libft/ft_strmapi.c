/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:40:35 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:40:37 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>

// A test function to pass to ft_strmapi
// It will convert even-indexed chars to 'X' and odd-indexed chars to 'O'
char	test_mapper(unsigned int i, char c)
{
	if (i % 2 == 0)
		return ('X');
	return ('O');
}

int	main(void)
{
	char	*s;
	char	*result;

	s = "abcde";
	printf("--- Testing ft_strmapi ---\n");
	result = ft_strmapi(s, &test_mapper);
	if (!result)
	{
		printf("Allocation failed!\n");
		return (1);
	}
	printf("Mapping \"abcde\": \"%s\" (Expected: \"XOXOX\")\n", result);
	free(result);
	return (0);
}
*/
