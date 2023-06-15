/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <raphaellrlevilla@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/04 02:10:59 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
/*
size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	char	*ptrdest;
	char	*ptrsrc;

	j = 0;
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	i = ft_strlen(ptrdest);
	if (destsize <= 0)
		return (0);
	else
	{
		while (i < (destsize - 1) && j < ft_strlen(ptrsrc))
		{
			ptrdest[i] = ptrsrc[j];
			i++;
			j++;
		}
		return (ft_strlen(ptrdest) + ft_strlen(ptrsrc));
	}
}*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize > i)
		res = ft_strlen((char *)src) + i;
	else
		res = ft_strlen((char *)src) + dstsize;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
/*
int main(void)
{
	char buffer[32];
	char s1[] = "0123456789";
	char s2[] = "abcdef";

	strcpy(buffer, s1);
	strlcat(buffer, s2, 10);
	printf("%s\n", buffer); // devrait afficher '0123456789'
	printf("%zu\n", strlcat(buffer, s2, 10));
	ft_strlcat(buffer, s2, 10);
	printf("%s\n", buffer);
	printf("%zu\n\n", ft_strlcat(buffer, s2, 10));
	
	strcpy(buffer, s1);
	strlcat(buffer, s2, 13);
	printf("%s\n", buffer); // devrait afficher '0123456789ab'
	printf("%zu\n", strlcat(buffer, s2, 13));
	ft_strlcat(buffer, s2, 13);
	printf("%s\n", buffer);
	printf("%zu\n\n", ft_strlcat(buffer, s2, 13));

 
	strcpy(buffer, s1);
	strlcat(buffer, s2, 16);
	printf("%s\n", buffer); // devrait afficher '0123456789abcde'
	printf("%zu\n", strlcat(buffer, s2, 16));
	ft_strlcat(buffer, s2, 16);
	printf("%s\n", buffer);
	printf("%zu\n\n", ft_strlcat(buffer, s2, 16));


	strcpy(buffer, s2);
	strlcat(buffer, s1, 10);
	printf("%s\n", buffer); // devrait afficher 'abcdef012'
	printf("%zu\n", strlcat(buffer, s1, 10));
	ft_strlcat(buffer, s1, 10);
	printf("%s\n", buffer);
	printf("%zu\n\n", ft_strlcat(buffer, s1, 10));

	strcpy(buffer, s2);
	strlcat(buffer, s1, 14);
	printf("%s\n", buffer); // devrait afficher 'abcdef0123456'
	printf("%zu\n", strlcat(buffer, s1, 14));
	ft_strlcat(buffer, s1, 14);
	printf("%s\n", buffer);
	printf("%zu\n\n", ft_strlcat(buffer, s1, 14));

	char dest[32] = "0123456789";
	char src[] = "abcdef";
	ft_strlcat(dest, src, 13);
	printf("%s\n", dest);
}*/
