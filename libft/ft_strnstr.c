/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <raphaellrlevilla@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/04 02:25:58 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
/*
char	*ft_strnstr(char *str, char *search, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n <= 0)
		return (str);
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == search[j])
		{
			while (str[i+j] == search[j] && i+j < n)
			{
				j++;
				if (search[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *str = "Alors le ptit bg de la manana";
	char *search = "ptit";
	size_t n = 8;

	printf("%s\n", strnstr(str, search, n));
	printf("%s\n", ft_strnstr(str, search, n));
}*/
