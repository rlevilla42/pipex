/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:31:54 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/16 18:37:56 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_hexasize(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
*/
int	ft_itoa_base_p(unsigned long long n, char *base)
{
	int		i;
	int		len;
	char	*str;

	i = ft_hexasize(n);
	str = (char *)malloc(sizeof(char) * ft_hexasize(n) + 1);
	if (str == NULL)
		return (0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[i] = '0';
	}
	while (n > 0)
	{
		str[i--] = base[n % 16];
		n /= 16;
	}
	len = ft_putstr(str);
	free(str);
	return (len + 2);
}

int	ft_printf_p(unsigned long long int n, char *base)
{
	write(1, "0", 1);
	write(1, "x", 1);
	return (ft_itoa_base_p(n, base));
}
/*
int main(void)
{
	//unsigned int	n = 4294967295;
	//unsigned long long n = 18446744073709551615;
	unsigned long long n = 2147483647;
	void	*ptr = &n;
	int	n1 = 2147483646;
	int	*ptrn1 = &n1;
	long	n2 = 4294967295;
	long	*ptrn2 = &n2;
	printf("printf output this: %p\n", (void *)&n);
	printf("%d\n", ft_printf_p((uintptr_t)(void *)&n, "0123456789abcdef"));
	printf("printf output this: %p\n", ptr);
	printf("%d\n", ft_printf_p((uintptr_t)ptr, "0123456789abcdef"));
	printf("%d\n\n", ft_printf_p((unsigned long)ptr, "0123456789abcdef"));
	printf("printf output this: %p\n", ptrn1);
	printf("printf output this ( void *) cast: %p\n", (void *)ptrn1);
	printf("%d\n", ft_printf_p((uintptr_t)ptrn1, "0123456789abcdef"));
	printf("%d\n", ft_printf_p((unsigned long)ptrn1, "0123456789abcdef"));
	printf("%d\n\n", ft_printf_p((long)ptrn1, "0123456789abcdef"));
	printf("printf output this: %p\n", ptrn2);
	printf("printf output this ( void *) cast: %p\n", (void *)ptrn2);
	printf("%d\n", ft_printf_p(ptrn2, "0123456789abcdef"));
	printf("%d\n", ft_printf_p((uintptr_t)ptrn2, "0123456789abcdef"));
	printf("%d\n", ft_printf_p((unsigned long)ptrn2, "0123456789abcdef"));
	printf("%d\n", ft_printf_p((long)ptrn2, "0123456789abcdef"));
}*/
