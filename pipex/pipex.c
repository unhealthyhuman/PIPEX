/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:39:05 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/04 19:25:46 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_master(void)
{
	perror("PIPEX FAILURE");
	exit (1);
}

void	freeme(char **array)
{
	int	i;

	i = 0;
	while(array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	main(int argc, char **argv, char **envp)
{
	int	id;
	int	id2;
	int	pipe_fd[2];

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			perror_master();
		id = fork();
		if (id == -1)
			perror_master();
		else if (id == 0)
			child1(argv[1], argv[2], pipe_fd, envp);
		close(pipe_fd[1]);
		id2 = fork();
		if (id2 == -1)
			perror_master();
		else if (id2 == 0)
			child2(&pipe_fd[0], argv[3], argv[4], envp);
		close(pipe_fd[0]);
		wait(0);
		wait(0);
	}
	return (0);
}
