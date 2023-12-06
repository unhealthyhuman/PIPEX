#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

void	checkity_check(char *file);
void	child1(char *input_file, char *command, int pipe_fd[], char **envp);
void	checkity_check2(char *file);
void	child2(int pipe_fd[], char *command, char *output_file, char **envp);
char	**find_and_split_path(char **envp);
char	*is_it_me(char **paths, char **command_line);
void	perror_master();
void	freeme(char **array);

#endif