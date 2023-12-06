#include "pipex.h"

//first child processes the first command and executes it, it outputs a tmp file

void	checkity_check(char *file)
{
	int permission;

	permission = access(file, F_OK);

	if (permission == -1)
		perror_master();
	permission = access(file, R_OK);
	if (permission == -1)
		perror_master();
}

void	child1(char *input_file, char *command, int pipe_fd[], char **envp)
{
	int		file_fd;
	char	**paths1;
	char	**cmd1;
	char	*it_is_me;

	checkity_check(input_file);
	file_fd = open(input_file, O_RDONLY);
	if (file_fd == -1)
		perror_master();
	paths1 = find_and_split_path(envp);
	if (!paths1)
		perror_master();
	cmd1 = ft_split(command, ' ');
	if (!cmd1)
		return (freeme(paths1));
	it_is_me = is_it_me(paths1, cmd1);
	if (it_is_me == 0)
	{
		freeme(paths1);
		freeme(cmd1);
		perror_master();
	}
	if (dup2(file_fd, 0) == -1)
	{
		freeme(paths1);
		freeme(cmd1);
		perror_master();
	}
	if (dup2(pipe_fd[1], 1) == -1)
	{
		freeme(paths1);
		freeme(cmd1);
		perror_master();
	}
	close(pipe_fd[0]);
	execve(it_is_me, cmd1, envp);
	free(it_is_me);
	freeme(cmd1);
	freeme(paths1);
}

/* {
		ft_putstr_fd("Command not found!\n", 2);
		exit (127);
	} */