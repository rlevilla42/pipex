/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:13:18 by raphaellevillain  #+#    #+#             */
/*   Updated: 2022/11/03 19:44:09 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	k;
	char	*ptrdest;
	char	*ptrsrc;
	char	buffer[100];

	i = 0;
	k = -1;
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	while (i < n)
	{
		buffer[i] = ptrsrc[i];
		i++;
	}
	buffer[i] = '\0';
	while (buffer[++k] != '\0')
	{
		ptrdest[k] = buffer[k];
	}
	ptrdest[k] = '\0';
	return (ptrdest);
}
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)src;
	i = 0;
	if ((char *)dst == temp)
		return (dst);
	else if ((char *)dst > temp)
		while (len-- > 0)
			((char *)dst)[len] = temp[len];
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = temp[i];
			i++;
		}
	}
	return (dst);
}
/*
int main(void)
{
	char src[100] = "Yo bg de la manana";
	char dest[100];
	ft_memmove(dest, src, 10);
	printf("Voila ce que output mon ptit ft_memmove de bg: %s\n", dest);
	
	char src2[100] = "Yo bg de la manana";
	char dest2[100];
	memmove(dest2, src2, 10);
	printf("Ce que MEMMOVE ORIGINAL OUTPUT: %s\n\n", dest2);
	

	char src3[100] = "Yo bg de la manana";
	char dest3[100];
	ft_memmove(dest3, src3, 18);
	printf("Voila ce que output mon ptit ft_memmove de bg: %s\n", dest3);
	
	char src4[100] = "Yo bg de la manana";
	char dest4[100];
	memmove(dest4, src4, 18);
	//quand size_t n > strlen(src) alors ca marche mieux que lorsque
	//n = strlen(src)
	printf("Ce que MEMMOVE ORIGINAL OUTPUT: %s\n", dest4);
}*/
