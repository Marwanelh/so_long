/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:26:47 by mael-hou          #+#    #+#             */
/*   Updated: 2025/09/01 14:26:47 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h> // For bzero on some systems

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *p = b;
    while (len-- > 0)
        *p++ = (unsigned char)c;
    return (b);
}

void    print_hex(const char *label, const void *ptr, size_t size)
{
    const unsigned char *p = ptr;
    printf("%-15s: ", label);
    for (size_t i = 0; i < size; i++)
        printf("%02x ", p[i]);
    printf("\n");
}

int main(void)
{
    char    buffer_ft[15] = "Hello World!";
    char    buffer_std[15] = "Hello World!";

    printf("--- Comparing ft_bzero against system bzero ---\n\n");
    
    printf("--- Test: Zeroing out 5 bytes ---\n");
    print_hex("Before (ft)", buffer_ft, 15);
    print_hex("Before (std)", buffer_std, 15);
    printf("\n");
    
    ft_bzero(buffer_ft, 5);
    bzero(buffer_std, 5);
    
    print_hex("After (ft)", buffer_ft, 15);
    print_hex("After (std)", buffer_std, 15);

    if (memcmp(buffer_ft, buffer_std, 15) == 0)
        printf("Result: ✅ SUCCESS\n");
    else
        printf("Result: ❌ FAILURE\n");

    return (0);
}
*/
