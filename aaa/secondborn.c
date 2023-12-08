/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondborn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:55:36 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/07 13:41:19 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	checkity_check2(char *file)
{
	int	permission;

	permission = access(file, F_OK);
	if (permission == -1)
	{
		perror("PIPEX FAILURE1");
		return ;
	}
	permission = access(file, W_OK);
	if (permission == -1)
		perror_master();
}

void	child2(int pipe_fd[], char *command, char *output_file, t_data *data)
{
	data->output_fd = open(output_file, O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (data->output_fd == -1)
		perror_master();
	checkity_check(output_file);
	if (dup2(data->output_fd, 1) == -1)
		perror_master();
	if (dup2(pipe_fd[0], 0) == -1 || close(pipe_fd[0]) == -1
		|| close(pipe_fd[1]) == -1)
		perror_master();
	data->path2 = find_and_split_path(data->environment);
	if (!data->path2)
		perror_master();
	data->cmd2 = ft_split(command, ' ');
	if (!data->cmd2)
		return (freeme(data->path2));
	data->it_is_me = is_it_me(data->path2, data->cmd2, data);
	if (data->it_is_me == 0)
	{
		freeboss(data->path2, data->cmd2);
		perror_master();
	}
	execve(data->it_is_me, data->cmd2, data->environment);
	free(data->it_is_me);
	freeboss(data->path1, data->cmd2);
}
