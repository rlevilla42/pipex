/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <raphaellrlevilla@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/03 20:57:53 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
int main(void)
{
	char str[100] = "Salut petit foufou";
	int c = 'Z';
	size_t n = 9;
	memset(str, c, n);
	printf("Ce que ressort le VRAI memset: %s\n", str);
	char str2[100] = "Salut petit foufou";
	int c2 = 'Z';
	size_t n2 = 9;
	ft_memset(str2, c2, n2);
	printf("Ce que ressort MON ft_memset: %s\n", str2);

}
*/
