#ifndef	PIPEX_H
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
}	pipe_t;

void	turbo_exec(char **cmd, pipe_t *pipe, char **env);
void	write_error(char *str);
#endif
