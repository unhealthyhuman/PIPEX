/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstborn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:56:37 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/07 14:00:20 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//first child processes the first command and executes it, it outputs a tmp file

void	checkity_check(char *file)
{
	int	permission;

	permission = access(file, F_OK);
	if (permission == -1)
		perror_master();
	permission = access(file, R_OK);
	if (permission == -1)
		perror_master();
}

void	child1(char *input_file, char *command, int pipe_fd[], t_data *data)
{
	checkity_check(input_file);
	data->file_fd = open(input_file, O_RDONLY);
	if (data->file_fd == -1)
		perror_master();
	if (dup2(data->file_fd, 0) == -1)
		perror_master();
	if (dup2(pipe_fd[1], 1) == -1 || close(pipe_fd[0]) == -1
		|| close(pipe_fd[1]) == -1)
		perror_master();
	data->path1 = find_and_split_path(data->environment);
	if (!data->path1)
		perror_master();
	data->cmd1 = ft_split(command, ' ');
	if (!data->cmd1)
		return (freeme(data->path1));
	data->it_is_me = is_it_me(data->path1, data->cmd1, data);
	if (data->it_is_me == 0)
	{
		freeboss(data->path1, data->cmd1);
		perror_master();
	}
	execve(data->it_is_me, data->cmd1, data->environment);
	free(data->it_is_me);
	freeboss(data->path1, data->cmd1);
}
