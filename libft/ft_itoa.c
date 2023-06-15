/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:48:46 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/09 20:42:08 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_int_malloc(int n)
{
	int	k;

	k = 0;
	if (n < 0 && n > -2147483648)
	{
		n *= (-1);
		while (n > 0)
		{
			n /= 10;
			k++;
		}
	}
	return (k + 1);
}

int	ft_intsize(int n)
{
	int	k;

	k = 0;
	if (n == 0)
		return (1);
	if (n < 0 && n > -2147483648)
	{
		return (ft_int_malloc(n));
	}
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			k++;
		}
	}
	else if (n == -2147483648)
		return (11);
	return (k);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	*buffer;

	i = ft_intsize(n);
	num = n;
	buffer = (char *)malloc(sizeof(char) * ft_intsize(n) + 1);
	if (!buffer)
		return (NULL);
	buffer[i--] = '\0';
	if (n < 0)
	{
		buffer[0] = '-';
		num = num * (-1);
	}
	else if (num == 0)
		buffer[i] = '0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + 48;
		num /= 10;
	}
	return (buffer);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(-2147483647));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(214774));
	printf("%s\n", ft_itoa(-21474836));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n\n", ft_itoa(-1));
	printf("-2147483648 = %d\n", ft_intsize(-2147483648));
	printf("-2147483647 = %d\n", ft_intsize(-2147483647));
	printf("2147483647 = %d\n", ft_intsize(2147483647));
	printf("214774 = %d\n", ft_intsize(214774));
	printf("-21474836 = %d\n", ft_intsize(-21474836));
	printf("0 = %d\n", ft_intsize(0));
	printf("1 = %d\n", ft_intsize(1));
	printf("-1 = %d\n", ft_intsize(-1));
}*/
