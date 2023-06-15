/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:16:08 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/16 16:32:23 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/*
int	ft_intsize(int n)
{
	int		count;
	long	num;

	count = 0;
	num = n;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		num *= (-1);
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
*/
int	ft_putstr_free(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		count++;
		i++;
	}
	free(str);
	return (count);
}

int	ft_itoa_int(int n)
{
	char	*str;
	int		i;
	long	num;

	str = (char *)malloc(sizeof(char) * ft_intsize(n) + 1);
	if (!str)
		return (0);
	i = ft_intsize(n);
	num = n;
	str[i--] = '\0';
	if (num == 0)
		str[i] = '0';
	else if (num < 0)
	{
		num *= (-1);
		str[0] = '-';
	}
	while (num > 0)
	{
		str[i--] = (num % 10) + 48;
		num /= 10;
	}
	return (ft_putstr_free(str));
}

int	ft_printf_int(int n)
{
	return (ft_itoa_int(n));
}
/*
int main(void)
{
	printf("%d\n", ft_itoa(-2147483648));
	printf("%d\n", ft_itoa(-2147483647));
	printf("%d\n", ft_itoa(2147483647));
	printf("%d\n", ft_itoa(214774));
	printf("%d\n", ft_itoa(-21474836));
	printf("%d\n", ft_itoa(0));
	printf("%d\n", ft_itoa(1));
	printf("%d\n\n", ft_itoa(-1));
	printf("-2147483648 = %d\n", ft_intsize(-2147483648));
	printf("-2147483647 = %d\n", ft_intsize(-2147483647));
	printf("2147483647 = %d\n", ft_intsize(2147483647));
	printf("214774 = %d\n", ft_intsize(214774));
	printf("-21474836 = %d\n", ft_intsize(-21474836));
	printf("0 = %d\n", ft_intsize(0));
	printf("1 = %d\n", ft_intsize(1));
	printf("-1 = %d\n", ft_intsize(-1));
}*/
