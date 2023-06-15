/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaell <rlevilla@student.42.fr>  	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:13:18 by raphaell          #+#    #+#             */
/*   Updated: 2022/11/04 02:46:04 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/*
size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	b;
	char	*buffer;

	i = -1;
	j = -1;
	b = -1;
	buffer = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (buffer == NULL)
		return (NULL);
	while (s1[++i] != '\0' && set[++j] != '\0')
	{
		if (s1[i] == set[0] || s1[i] == set[ft_strlen(set) - 1])
			j = -1;
		else 
		{
			buffer[++b] = s1[i];
			j = -1;
		}
	}
	buffer[++b] = '\0';
	return (buffer);
}
*/

static int	ft_getstart(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static int	ft_getend(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0)
	{
		if (ft_strchr(set, s1[i - 1]) == NULL)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (start >= end)
	{
		return (ft_strdup(""));
	}
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < (end - start))
	{
		str[i] = s1[i + start];
	}
	str[i] = '\0';
	return (str);
}
/*
int main(void)
{
	char *s1 = "Salut nigo";
	char	*set = "uto";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/
