/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:22:11 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/11 00:45:19 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
/*
size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
*/

char	**ft_free_array(char **ptrptrs)
{
	size_t	j;

	j = 0;
	while (ptrptrs[j] != NULL)
	{
		free(ptrptrs[j]);
		j++;
	}
	free(ptrptrs[j]);
	free(ptrptrs);
	return (NULL);
}

size_t	ft_countc(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

size_t	ft_strsize(char const *s, char c)
{
	size_t	i;
	size_t	count_size;

	i = 0;
	count_size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count_size++;
		i++;
	}
	return (count_size);
}

char	*ft_strdup_split(char const *s, char c)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * (ft_strsize(s, c) + 1));
	if (!buffer)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**ptrptrs;
	size_t	j;

	ptrptrs = (char **)malloc(sizeof(char *) * (ft_countc(s, c) + 1));
	if (!ptrptrs)
		return (NULL);
	j = -1;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			++s;
		if (*s != c && *s != '\0')
		{
			ptrptrs[++j] = ft_strdup_split(s, c);
			if (ptrptrs[j] == NULL)
				return (ft_free_array(ptrptrs));
			while (*s != c && *s != '\0')
				++s;
		}
	}
	ptrptrs[++j] = NULL;
	return (ptrptrs);
}
/*
int main(void)
{
	// test FINAL

	char	str[] = "..Macron..e.st.un.pedo.sataniste";
	char	str2[] = "hello!";
	char	c = '.';
	char	c1 = ' ';
	size_t	i = 0;
	size_t	j = 0;
	char	**ptrptrs;
	char	**ptrptrs2;

	ptrptrs = ft_split(str, c);
	printf("Voici ce que output ft_split normal:\n\n");
	while (ptrptrs[i] != 0)
	{
		printf("%s\n", ptrptrs[i]);

		i++;
	}
	printf("%s\n\n", ptrptrs[i]);
	printf("Voici ce que output ft_split BUGGE:\n\n");
	ptrptrs2 = ft_split(str2, c1);
	while (ptrptrs2[j] != 0)
	{
		printf("%s\n", ptrptrs2[j]);

		j++;
	}
	printf("%s\n", ptrptrs2[j]);
}
*/
/*
int main(void)
{
	// test ft_countc;

	char	str[] = "hello!";
	char	str2[] = "..Macron.e.st.pdo.sataniste..";
	char	str3[] = "..Macron.e.st.pdo.sataniste";
	char	c = ' ';
	char	c1 = '.';
	size_t	k = ft_countc(str, c);
	size_t	k1 = ft_countc(str2, c1);
	size_t	k2 = ft_countc(str3, c1);
	printf("%zu\n", k);
	printf("%zu\n", k1);
	printf("%zu\n", k2);
}
*/
/*
int main(void)
{
    // test FINAL

    char    str[] = "..Macron..e.st.un.pedo.sataniste..";
    char    c = '.';
    size_t    i = 0;
    char    **ptrptrs;

    ptrptrs = ft_split(str, c);
    while (ptrptrs[i] != 0)
    {
        printf("%s\n", ptrptrs[i]);
        free(ptrptrs[i]);
        i++;
    }
    free(ptrptrs);
}
*/
/*
int main(void)
{
	// test ft_slen len pour chaque str

	char	str[] = "hello!!!!";
	char	str2[] = "..Macron.e.st.un.pedo.sataniste..";
	char	str3[] = "..Macron.e.st.un.pedo.sataniste";
	char	*s = str;
	char	*s2 = str2;
	char	*s3 = str3;
	char	c = ' ';
	char	c2 = '.';
	char	c3 = '.';
	while (*s != '\0')
	{
		if (*s != c)
		{
			printf("%zu\n", ft_strsize(s, c));
			while (*s != c && *s != '\0')
			{
				++s;
			}
		}
		while (*s == c)
		{
			++s;
		}
	}
	printf("||| RETOUR A LA LIGNE |||\n");
	while (*s2 != '\0')
	{
		if (*s2 != c2)
		{
			printf("%zu\n", ft_strsize(s2, c2));
			while (*s2 != c2 && *s2 != '\0')
			{
				++s2;
			}
		}
		while (*s2 == c2)
		{
			++s2;
		}
	}
	printf("||| RETOUR A LA LIGNE |||\n");
	while (*s3 != '\0')
	{
		if (*s3 != c3)
		{
			printf("%zu\n", ft_strsize(s3, c3));
			while (*s3 != c3 && *s3 != '\0')
			{
				++s3;
			}
		}
		while (*s3 == c3)
		{
			++s3;
		}
	}
}*/
