/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:26:41 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:26:41 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void run_test(const char *s)
{
    printf("--- Testing string \"%s\" ---\n", s);
    
    int res_ft = ft_atoi(s);
    int res_std = atoi(s);

    printf("ft_atoi result: %d\n", res_ft);
    printf("atoi result:    %d\n", res_std);

    if (res_ft == res_std)
        printf("Result: ✅ SUCCESS\n\n");
    else
        printf("Result: ❌ FAILURE\n\n");
}

int main(void)
{
    printf("--- Comparing ft_atoi against system atoi ---\n\n");
    run_test("42");
    run_test("   -123  ");
    run_test("+999test");
    run_test("--67");
    run_test("word");
    run_test("2147483647");
    run_test("-2147483648");
    run_test("  \t\n\v\f\r+1234 567");
    run_test("\n\n\n  -42\t\n");
    return (0);
}
*/
