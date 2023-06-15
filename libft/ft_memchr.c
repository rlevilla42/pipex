/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:13:18 by raphaellevillain  #+#    #+#             */
/*   Updated: 2022/11/08 01:35:32 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptrstr;
	size_t			i;
	unsigned char	c1;

	i = 0;
	ptrstr = (unsigned char *)str;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (ptrstr[i] == c1)
		{
			return ((void *)ptrstr + i);
		}
		i++;
	}	
	return (NULL);
}
/*
int main(void)
{
	char *str = "Fuck les pedo s/o Chenzen aka freeze rael";
	char *ptrmemchr = memchr(str, 'k', 4);
	printf("memchr output this: %s\n", ptrmemchr);

	char *str1 = "Fuck les pedo s/o Chenzen aka freeze rael";
	char *ptrft_memchr = ft_memchr(str1, 'k', 4);
	printf("ft_memchr output this: %s\n\n", ptrft_memchr);


	char *str3 = "Fuck les pedo s/o Chenzen aka freeze rael";
	char *ptrmemchr2 = memchr(str3, 'k', 3);
	printf("memchr output this: %s\n", ptrmemchr2);

	char *str4 = "Fuck les pedo s/o Chenzen aka freeze rael";
	char *ptrft_memchr3 = ft_memchr(str4, 'k', 3);
	printf("ft_memchr output this: %s\n\n", ptrft_memchr3);
	char	*str5;
	str5 = ft_memchr("bonjourno", 'n', 2);
	char	*s;
	s = memchr("bonjourno", 'n', 2);
	printf("%s\n", str5);
	printf("%s\n\n", s);
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
    	printf("%s\n", (char *)memchr(tab, -1, 7));
}*/
