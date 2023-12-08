/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:53:52 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/07 13:43:41 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_data
{
	char		**environment;
	char		**cmd1;
	char		**cmd2;
	char		**path1;
	char		**path2;
	char		*it_is_me;
	char		*tmp;
	char		*to_check;
	int			output_fd;
	int			file_fd;
	int			id;
	int			id2;
	int			exitstatus;
	int			i;
}	t_data;

void	checkity_check(char *file);
void	child1(char *input_file, char *command, int pipe_fd[], t_data *data);
void	checkity_check2(char *file);
void	child2(int pipe_fd[], char *command, char *output_file, t_data *data);
char	**find_and_split_path(char **envp);
char	*is_it_me(char **paths, char **command_line, t_data *data1);
void	perror_master(void);
void	freeme(char **array);
void	freeboss(char **path, char **cmd);

#endif