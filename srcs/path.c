/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:06:20 by rlevilla          #+#    #+#             */
/*   Updated: 2023/06/16 18:19:49 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *full_cmd, t_pipe *pipex)
{
	int		i;
	int		j;
	char	*final_path;

	i = 0;
	j = 0;
	while (pipex->path_split[j] != NULL)
	{
		final_path = ft_strjoin(pipex->path_split[j], full_cmd);
		if (final_path == NULL)
			write_error("Path_final is DEAD ??\n");
		else
			free(pipex->path_split[j]);
		if (access(final_path, X_OK) == 0)
			break ;
		j++;
	}
	free(pipex->path_split);
	return (final_path);
}

int	find_j_path(t_pipe *pipex, char **env)
{
	int	j;

	j = 0;
	while (env[j] != NULL)
	{
		pipex->path = ft_strnstr(env[j], "PATH", 5);
		if (pipex->path != NULL)
			break ;
		j++;
	}
	return (j);
}

void	turbo_exec(char **cmd, t_pipe *pipex, char **env)
{
	int		i;
	int		j;
	char	*full_cmd;
	char	*final_path;

	j = find_j_path(pipex, env);
	i = 0;
	while (i < 6)
	{
		pipex->path++;
		i++;
	}
	pipex->path_split = ft_split(pipex->path, ':');
	if (pipex->path_split == NULL)
		write_error("split errooor laaaa\n");
	j = 0;
	full_cmd = ft_strjoin("/", cmd[0]);
	if (full_cmd == NULL)
		write_error("full_cmd return NULL car ft_strjoin error zehbi\n");
	final_path = get_path(full_cmd, pipex);
	if (final_path == NULL)
		write_error("this cmd line doesn't exist\n");
	if (execve(final_path, cmd, env) == -1)
		write_error("execve error ??\n");
}
/*
int	main(int argc, char **argv, char **env)
{
	pipe_t	pipe;
	(void)argc;
	(void)argv;

	turbo_exec(NULL, &pipe, env);
	return (0);
}*/
