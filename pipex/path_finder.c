#include "pipex.h"

char	**find_and_split_path(char **envp)
{
	int	i;

	//changed i to -1 to keep increasing i in loop without losing i = 0;
	i = -1;
	while (envp[++i] != 0)
	{
		char	*path;
		char	**paths;
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i]);
			if (!path)
				return (NULL);
			paths = ft_split(path, ':');
			free(path);
			if (!paths)
				return (NULL);
			return(paths);
		}
	}
	return (0);
}

char	*is_it_me(char **paths, char **command_line)
{
	int		i;

	i = 0;

	// Check if relative path (starts with .) or absolute path (starts with /)
	if (command_line == NULL || paths == NULL)
		perror_master();
	if (command_line[0][0] == '/' || command_line[0][0] == '.')
	{
		freeme(paths);
		return (command_line[0]);
	}
	while (paths[i] != NULL)
	{
		char	*tmp;
		char	*to_check;

		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
		{
			freeme(command_line);
			freeme(paths);
			perror_master();
		}
		to_check = ft_strjoin(tmp, command_line[0]);
		free(tmp);
		if (!to_check)
		{
			freeme(command_line);
			freeme(paths);
			free(tmp);
			perror_master();
		}
		if (access(to_check, X_OK) == 0)
			return (to_check);
		free(to_check);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
int main(int argc, char **argv, char **envp)
{
	int i = 0;
	char **paths;
	char *itsme;

	paths = find_and_split_path(envp);
	itsme = is_it_me(paths, "cat");
	//while(paths[i] != 0)
	//{
	//	printf("%s", paths[i]);
	//	i++;
	//}
	printf("%s\n", itsme);
} */
