/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:18:46 by rlevilla          #+#    #+#             */
/*   Updated: 2022/12/12 16:30:28 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_strchr(char *temp);
char	*gnl_strndup(char *temp, char c);
char	*gnl_find_str_toreturn(char *temp);
char	*search_line(int fd, char *temp);
char	*gnl_strjoin(char *temp, char *buf, ssize_t bytes_read);
char	*gnl_calloc(ssize_t buf_size);
ssize_t	check_c(char *temp);
//ssize_t	ft_strlen(char *str);

#endif
