/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <raphaellrlevilla@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/08 16:49:43 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	int		j;
	int		flag;
	char	ch;
	char	*str;

	i = 0;
	j = 0;
	flag = 0;
	ch = (char)c;
	str = (char *)string;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			j = i;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		return (&str[j]);
	else if (ch == '\0')
		return (&str[i]);
	return (NULL);
}
/*
int main(void)
{
	printf("%s\n", strrchr("teste", 0));
	printf("%s\n\n", ft_strrchr("teste", 0));
	printf("%s\n", strrchr("xteste", 'x'));
	printf("%s\n", ft_strrchr("xteste", 'x'));
}*/
