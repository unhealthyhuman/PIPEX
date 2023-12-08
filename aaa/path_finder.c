/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:44:20 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/07 14:19:39 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_and_split_path(char **envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = -1;
	while (envp[++i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i]);
			if (!path)
				return (NULL);
			paths = ft_split(path, ':');
			free(path);
			if (!paths)
				return (NULL);
			return (paths);
		}
	}
	return (0);
}

void	group_one(char **paths, char **command_line, t_data *data1)
{
	freeboss(paths, command_line);
	free(data1->tmp);
	perror_master();
}

char	*is_it_me(char **paths, char **command_line, t_data *data1)
{
	data1->i = 0;
	if (command_line == NULL || paths == NULL)
		perror_master();
	if (command_line[0][0] == '/' || command_line[0][0] == '.')
		return (freeme(paths), command_line[0]);
	while (paths[data1->i] != NULL)
	{
		data1->tmp = ft_strjoin(paths[data1->i], "/");
		if (!data1->tmp)
		{
			freeboss(paths, command_line);
			perror_master();
		}
		data1->to_check = ft_strjoin(data1->tmp, command_line[0]);
		free(data1->tmp);
		if (!data1->to_check)
			group_one(paths, command_line, data1);
		if (access(data1->to_check, X_OK) == 0)
			return (data1->to_check);
		free(data1->to_check);
		data1->i++;
	}
	return (0);
}

//instead of group_one we had
//{
//freeboss(paths, command_line);
//free(data1->tmp);
//perror_master();
//}
