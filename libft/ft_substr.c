/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <rlevilla@student.42.fr>  	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/04 02:47:39 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/*
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(const char *s1, unsigned int start, size_t len)
{
	size_t	i;
	size_t	start1;
	char	*dest;
	char	*s2;

	i = 0;
	start1 = (size_t)start;
	s2 = (char *)s1;
	dest = malloc(sizeof(*s1) * (len + 1));
	if (dest == NULL)
		return (NULL);
	else if (start1 > len || (start1 + 1) > len || start1 > ft_strlen(s2))
		return (NULL);
	while (s1[start1] != '\0' && (i < len))
	{
		dest[i] = s1[start1];
		i++;
		start1++;
	}
	return (dest);
}
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s + start, len + 1);
	return (str);
}
/*
int main(void)
{	const char	*s1 = "Bonjour chenzen aka freeze rael";
	unsigned int	start = 3;
	size_t	len =  12;

	printf("%s\n", ft_substr(s1, start, len));
	free(ft_substr(s1, start, len));
}
*/
/*#1. La chaine de laquelle extraire la nouvelle
chaine
#2. L’index de début de la nouvelle chaine dans la
chaine ’s’.
#3. La taille maximale de la nouvelle chaine.
Valeur de retour The nouvelle chaine de caractere. NULL si
l’allocation échoue.
Fonctions externes autorisées
malloc
Description Alloue (avec malloc(3)) et retourne une chaine de
caractères issue de la chaine ’s’.
Cette nouvelle chaine commence à l’index ’start’ et
a pour taille maximale ’len’
*/
