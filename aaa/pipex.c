/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:39:05 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/07 14:23:12 by ischmutz         ###   ########.fr       */
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
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	freeboss(char **path, char **cmd)
{
	freeme(path);
	freeme(cmd);
}

void	wait_for_offspring(t_data *data)
{
	waitpid(data->id, &data->exitstatus, 0);
	waitpid(data->id2, &data->exitstatus, 0);
	if (WIFEXITED(data->exitstatus))
		data->exitstatus = WEXITSTATUS(data->exitstatus);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		pipe_fd[2];

	data.environment = envp;
	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			perror_master();
		data.id = fork();
		if (data.id == -1)
			perror_master();
		else if (data.id == 0)
			child1(argv[1], argv[2], pipe_fd, &data);
		data.id2 = fork();
		if (data.id2 == -1)
			perror_master();
		else if (data.id2 == 0)
			child2(&pipe_fd[0], argv[3], argv[4], &data);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		wait_for_offspring(&data);
	}
	return (data.exitstatus);
}
