#include "pipex.h"

//first child processes the first command and executes it, it ourputs a tmp file
int	child1(char *input_file, char *command,int pipe_fd)
{
	if (open(input_file, O_CREAT) == -1)
		perror ("Error: No such file or directory found");
	if (open(input_file, O_RDONLY) == -1)
	{

	}
	pipe_fd == read(input_file, pipe_fd, sizeof(pipe_fd));

}