/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_majx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:48:20 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/16 16:33:42 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
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
int	ft_itoa_base(unsigned long long n, char *base)
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
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_printf_majx(unsigned long long n, char *base)
{
	return (ft_itoa_base(n, base));
}
/*
int main(void)
{
	//unsigned long long n = 4294967295;
	//unsigned long long n = 0;
	//unsigned long long n = 10;
	//unsigned long long n = 4;
	printf("%llX\n", n);
	printf("%d\n", ft_printf_x(n, "0123456789ABCDEF"));
}*/
