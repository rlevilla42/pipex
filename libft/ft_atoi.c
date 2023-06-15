/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <raphaellrlevilla@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/03 17:31:54 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	buffer;
	int	countminus;

	i = 0;
	countminus = 1;
	buffer = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			countminus = -1;
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		buffer = (buffer * 10) + (str[i] - 48);
		i++;
	}
	return (buffer * countminus);
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str = "\t\v\r9999";
	printf("atoi output this: %i\n", atoi(str));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str));
	
	char *str2 = "12\t345";
	printf("atoi output this: %i\n", atoi(str2));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str2));
	
	char *str3 = "-12345";
	printf("atoi output this: %i\n", atoi(str3));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str3));

	char *str4 = "--12345";
	printf("atoi output this: %i\n", atoi(str4));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str4));

	char *str5 = "+12345";
	printf("atoi output this: %i\n", atoi(str5));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str5));

	char *str6 = "-+12345";
	printf("atoi output this: %i\n", atoi(str6));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str6));

	char *str7 = "++12345";
	printf("atoi output this: %i\n", atoi(str7));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str7));
	
	char *str8 = "\t-12345";
	printf("atoi output this: %i\n", atoi(str8));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str8));
	
	char *str9 = "\t-\r12345";
	printf("atoi output this: %i\n", atoi(str9));
	printf("ft_atoi output this: %i\n\n", ft_atoi(str9));
	//printf("atoi output this: %i\n", atoi(argv[1]));
}*/
