#include "pipex.h"

void	checkity_check2(char *file)
{
	int permission;

	permission = access(file, F_OK);
	if (permission == -1)
	{
		perror("PIPEX FAILURE");
		return ;
	}
	permission = access(file, W_OK);
	if (permission == -1)
		perror_master();
}

void	child2(int pipe_fd[], char *command, char *output_file, char **envp)
{
	int		output_fd;
	char	**paths2;
	char	**cmd2;
	char	*it_is_moi;

	checkity_check2(output_file);

	output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dup2(pipe_fd[0], 0) == -1)
		perror_master();
	if (dup2(output_fd, 1) == -1)
		perror_master();
	paths2 = find_and_split_path(envp);
	cmd2 = ft_split(command, ' ');
	it_is_moi = is_it_me(paths2, cmd2);
	execve(it_is_moi, cmd2, envp);
	free(it_is_moi);
	free(cmd2);
	free(paths2);
	
}
