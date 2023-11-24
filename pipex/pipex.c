#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int	id;
	int	id2;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror ("Error ocurred in pipe");
		return (-1);
	}
	id = fork();
	if (id == -1)
	{
		perror("Error ocurred in fork");
		return (-1); //if u allocate smt before, u need to free it
	}
	if (id == 0);
	{
		do whatever child needs to do
		child1(argv[1], argv[2], pipe_fd);
	}
	else
	{
		close(child stops writing/change in permissions);
		id2 = fork();
		if (id2 == -1)
		{
			perror ("Error ocurred in fork 2");
			return (-1);
		}
		if (id2 == 0)
		{
			second child does smt;
		}

	}
	
}