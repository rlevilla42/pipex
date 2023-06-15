/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:13:18 by raphaellevillain  #+#    #+#             */
/*   Updated: 2022/11/03 19:26:28 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptrsrc;
	char	*ptrdest;

	i = 0;
	ptrsrc = (char *)src;
	ptrdest = (char *)dest;
	if (src == NULL && dest == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (ptrdest);
}
/*
int main(void)
{
	char str[100] = "LearningIsFun";
	char *first;
	char *first2;
	char str2[100] = "LearningIsFun";

	first = str;
	second = str;
	first2 = str2;
	printf("Original str is: %s\n", str);
	
	//char str1[100] = "LearningIsFun";
	memcpy(first+8, first, 10);
	printf("memcpy str is: %s\n", str);
	
	ft_memcpy(first2+8, first2, 10);
	printf("Ft_memcpy str is: %s\n", str2);

	char str3[100] = "";
	char	dest[100] = "YO LE RAP";
	memcpy(dest, str3, 10);
	printf("memcpy en string null renvoi :%s\n", dest);

	char str4[100] = "";
	char	dest1[100] = "YO LE RAP";
	ft_memcpy(dest1, str4, 10);
	printf("ft_memcpy en string null renvoi :%s\n", dest);
}


int main(void)
{
	char	dest[100];
	char	*src = "Salut ptit bg";
	memcpy(dest, src, 7);
	printf("Ce que la vraie fonction renvoie: %s\n", dest);
	
	char	dest2[100];
	char	*src2 = "Salut ptit bg";
	ft_memcpy(dest2, src2, 7);
	printf("Ce que la vraie fonction renvoie: %s\n", dest2);

	char	dest3[100];
	char	*src3 = "";
	ft_memcpy(dest3, src3, 7);
	printf("Ce que la vraie fonction renvoie: %s\n", dest3);

}
*/
