/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:21:29 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/16 16:34:54 by rlevilla         ###   ########.fr       */
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
int	ft_itoa_base_x(unsigned long long n, char *base)
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
	return (len);
}

int	ft_printf_x(unsigned long long n, char *base)
{
	return (ft_itoa_base_x(n, base));
}
/*
int main(void)
{
	//unsigned long long n = 4294967295;
	//unsigned long long n = 0;
	unsigned long long n = 10;
	//unsigned long long n = 4;
	printf("%llx\n", n);
	ft_printf_x(n, "0123456789abcdef");
}
*/
/*
int main(void)
{
	//unsigned int	n = 4294967295;
	// check ascii 

	printf("\tprintf output this:\t%lx\n", 4294967295);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(4294967295));
	
	printf("\tprintf output this:\t%x\n", 123456789);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(123456789));
	
	//unsigned int	n = 12345678;
	printf("\tprintf output this:\t%x\n", 98765432);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(98765432));
	
	printf("\tprintf output this:\t%x\n", 12345678);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(12345678));
	//unsigned int	n = 1234567;
	printf("\tprintf output this:\t%x\n", 17772835);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(17772835));
	
	//unsigned int	n = 123456;
	printf("\tprintf output this:\t%x\n", 666667);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(666667));
	
	//unsigned int	n = 12345;
	printf("\tprintf output this:\t%x\n", 91422);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(91422));
	
	//unsigned int	n = 1234;
	printf("\tprintf output this:\t%x\n", 9462);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(9462));
	
	//unsigned int	n = 123;
	printf("\tprintf output this:\t%x\n", 374);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(374));
	
	//unsigned int	n = 12;
	printf("\tprintf output this:\t%x\n", 12);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(12));
	
	//unsigned int	n = 1;
	printf("\tprintf output this:\t%x\n", 1);
	printf("\tft_uitoa return this:%d\n\n", ft_uitoa_base(1));
	
	printf("\tprintf output this:\t%lx\n", 4294967295);
	ft_uitoa_base(4294967295);

	printf("\tprintf output this:\t%x\n", 12345678);
	ft_uitoa_base(12345678);

	printf("\tprintf output this:\t%x\n", 91422);
	ft_uitoa_base(91422);
	//ft_uitoa_base(4294967295, "0123456789abcdef");
}
*/
