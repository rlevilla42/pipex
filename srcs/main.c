/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:06:20 by rlevilla          #+#    #+#             */
/*   Updated: 2023/06/17 00:21:51 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_error(char *str)
{
	perror(str);
	exit(1);
}

void	child_process(int *fd, t_pipe *pipex, char **argv, char **env)
{
	int		infile;
	char	**cmd;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	cmd = ft_split(argv[2], ' ');
	if (infile < 0)
		write_error("zehbi open error la OH\n");
	if (dup2(infile, STDIN_FILENO) < 0)
		write_error("dup2 fd, stdin_fileno in child_process error\n");
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		write_error("dup2 fd[1], stdout_fileno in child_process error\n");
	close(fd[1]);
	close(infile);
	turbo_exec(cmd, pipex, env);
}

void	parent_process(int *fd, t_pipe *pipex, char **argv, char **env)
{
	int		outfile;
	char	**cmd;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 000644);
	cmd = ft_split(argv[3], ' ');
	if (outfile < 0)
		write_error("open error in parent process\n");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		write_error("dup2 error pipe_fd[0] parent process\n");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		write_error("dup2 error outfile] parent process\n");
	close(fd[0]);
	close(outfile);
	turbo_exec(cmd, pipex, env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_pipe[2];
	t_pipe	pipex;

	if (argc != 5)
		write_error("Too much or too many arugmnts bro !\n");
	if (pipe(fd_pipe) == -1)
		write_error("Pipe function error bro!\n");
	pipex.p_fork1 = fork();
	if (pipex.p_fork1 < 0)
		write_error("fork error la ZEHBI\n");
	else if (pipex.p_fork1 == 0)
		child_process(fd_pipe, &pipex, argv, env);
	close(fd_pipe[1]);
	pipex.p_fork2 = fork();
	if (pipex.p_fork2 < 0)
		write_error("fork error la ZEHBI\n");
	else if (pipex.p_fork2 == 0)
		parent_process(fd_pipe, &pipex, argv, env);
	close(fd_pipe[0]);
	waitpid(pipex.p_fork1, NULL, 0);
	waitpid(pipex.p_fork2, NULL, 0);
	exit(0);
}
