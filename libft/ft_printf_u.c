/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:54:43 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/16 16:34:35 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_intlen(unsigned int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_itoa_u(unsigned int n)
{
	char	*str;
	int		i;
	int		count;

	str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1);
	i = ft_intlen(n);
	count = 0;
	if (str == NULL)
		return (0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[i] = n + 48;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_printf_u(unsigned int n)
{
	return (ft_itoa_u(n));
}
/*
int	main(void)
{
	unsigned int	nb = 4294967295;
	//unsigned int	nb = 0;
	//ft_itoa(nb);
	int z = ft_itoa(nb);
	printf("%d\n", z);
}*/
/*
int main (void)
{
	//unsigned int	n = 4294967295;
	printf("%u\n", ft_printf_u(0));
}*/
