/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <raphaellrlevilla@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/08 00:38:24 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
/*
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	nb;

	i = 0;
	nb = (int)n;
	if (n == 0)
		return (0);
	if (nb < 0)
	{
		return (-1);
	}
	while (s1[i] == s2[i] && i < nb - 1 && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main(void)
{	
	printf("%d\n", strncmp("1234", "12345", -1));
	printf("%d\n\n", ft_strncmp("1234", "12345", -1));
	printf("%d\n", strncmp("1234", "1235", -1));
	printf("%d\n\n", ft_strncmp("1234", "1235", -1));
	printf("%d\n", strncmp("ZZZZ", "a", -1));
	printf("%d\n\n", ft_strncmp("ZZZZ", "a", -1));
	printf("%d\n", strncmp("ZZZZ", "a", -8));
	printf("%d\n\n", ft_strncmp("ZZZZ", "a", -8));
	printf("%d\n", strncmp("ZZZZ", "a", 0));
	printf("%d\n", ft_strncmp("ZZZZ", "a", 0));
}*/
