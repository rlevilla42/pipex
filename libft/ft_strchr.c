/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <raphaellrlevilla@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/08 16:47:28 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *string, int c)
{
	int		i;
	char	*str;
	char	ch;

	i = 0;
	ch = (char)c;
	str = (char *)string;
	if (ch == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (&str[i]);
	}
	while (str[i] != ch && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0')
		return (NULL);
	else
		return (&str[i]);
}
/*
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr_temp;

	i = 0;
	ptr_temp = (char *)s;
	while (ptr_temp[i] != (char)c)
	{
		if (ptr_temp[i] == '\0')
			return (NULL);
		i++;
	}
	return (&ptr_temp[i]);
}

int main(void)
{
	printf("%s\n", ft_strchr("teste", '\0'));
	printf("%s\n", strchr("teste", '\0'));

}*/
