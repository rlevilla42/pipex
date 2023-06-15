/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:59:42 by rlevilla          #+#    #+#             */
/*   Updated: 2022/12/12 17:18:49 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
# define BUFFER_SIZE 42
*/
/*
ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
ssize_t	check_c(char *temp)
{
	ssize_t	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*gnl_strchr(char *temp)
{
	ssize_t	i;
	char	z;
	char	*str;

	i = 0;
	z = '\0';
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			i++;
			str = gnl_strndup(&temp[i], z);
			free(temp);
			return (str);
		}
		i++;
	}
	free(temp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*gnl;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	temp = search_line(fd, temp);
	if (temp == NULL)
	{
		free(temp);
		return (NULL);
	}
	gnl = gnl_find_str_toreturn(temp);
	temp = gnl_strchr(temp);
	return (gnl);
}
/*
int	main(void)
{
	int fd = open("gnl.txt", O_RDONLY);
	char	*line = get_next_line(fd);

	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}
*/
/*
int main(void)
{
	int fd = open("fullnl.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}
*/
/*
int main(void)
{
	int fd = open("43_no_nl.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
*/
/*
int main(void)
{
	int fd;
	char	*line;

	fd = open("43_no_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("BUFFER_SIZE =42\n43_no_nl.txt\n\n");
	while (line != NULL)
	{
		printf("GNL =%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("HORS BOUCLE =%s", get_next_line(fd));
	printf("HORS BOUCLE =%s", get_next_line(fd));
	printf("HORS BOUCLE =%s", get_next_line(fd));
	close(fd);
	return (0);
}*/
/*
int main(void)
{
	int fd;
	char	*line;

	fd = open("gnl.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("HORS BOUCLE =%s", get_next_line(fd));
	printf("HORS BOUCLE =%s", get_next_line(fd));
	printf("HORS BOUCLE =%s", get_next_line(fd));
	close(fd);
	return (0);
}
*/
/*
int main(void)
{
	int fd;
	//int	i;

	fd = open("41_with_nl.txt", O_RDONLY);
	//i = 0;
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
*/
