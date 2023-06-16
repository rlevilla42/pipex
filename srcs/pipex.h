/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:06:20 by rlevilla          #+#    #+#             */
/*   Updated: 2023/06/17 00:22:08 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct pipe
{
	char	**path_split;
	char	*path;
	int		fd[2];
	int		*rt_pipe;
	int		p_fork1;
	int		p_fork2;
}	t_pipe;

void	turbo_exec(char **cmd, t_pipe *pipe, char **env);
void	write_error(char *str);
void	error(char *msg);
#endif
