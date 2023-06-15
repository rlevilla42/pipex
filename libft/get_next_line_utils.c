/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:00:39 by rlevilla          #+#    #+#             */
/*   Updated: 2022/12/12 17:14:46 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*gnl_calloc(ssize_t buf_size)
{
	ssize_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * buf_size);
	if (!str)
		return (NULL);
	while (i < buf_size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*gnl_strndup(char *temp, char c)
{
	ssize_t	i;
	char	*str;

	i = 0;
	while (temp[i] != c)
		i++;
	if (c == '\n')
		i++;
	str = gnl_calloc(i + 1);
	i = 0;
	while (temp[i] != c)
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		str[i] = temp[i];
	return (str);
}

char	*gnl_find_str_toreturn(char *temp)
{
	char	*str;
	char	n;
	char	z;
	ssize_t	i;

	i = 0;
	n = '\n';
	z = '\0';
	if (temp[i] == '\0')
		return (NULL);
	if (check_c(temp) != -1)
	{
		str = gnl_strndup(temp, n);
	}
	else
	{
		str = gnl_strndup(temp, z);
	}
	return (str);
}

char	*gnl_strjoin(char *temp, char *buf, ssize_t bytes_read)
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	str = gnl_calloc(ft_strlen(temp) + bytes_read + 1);
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	while (j < bytes_read)
	{
		str[i] = buf[j];
		i++;
		j++;
	}
	free(temp);
	return (str);
}

char	*search_line(int fd, char *temp)
{
	ssize_t	bytes_read;
	char	*buf;

	bytes_read = 1;
	if (!temp)
		temp = gnl_calloc(1);
	buf = gnl_calloc(BUFFER_SIZE + 1);
	if (!buf || !temp)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			free(buf);
			return (NULL);
		}
		if (bytes_read != 0)
			temp = gnl_strjoin(temp, buf, bytes_read);
		if (check_c(temp) != -1)
			break ;
	}
	free(buf);
	return (temp);
}
