/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:32:44 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/21 10:13:26 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			words++;
		i++;
	}
	return (words);
}

static char	*put_strings(char const *s, char c)
{
	int		len;
	char	*str;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	str = ft_substr(s - len, 0, len);
	return (str);
}

static char	**freeme(char **gesplit)
{
	int	i;

	i = 0;
	while (gesplit[i])
	{
		free(gesplit[i]);
		i++;
	}
	free(gesplit);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**gesplit;
	int		i;
	int		len;

	i = 0;
	gesplit = (char **)malloc((count_words(s, c) + 1) * (sizeof(char *)));
	if (gesplit == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			gesplit[i] = put_strings(s, c);
			if (gesplit[i] == NULL)
				return (freeme(gesplit));
			len = ft_strlen(gesplit[i]);
			i++;
			s = s + len;
		}
	}
	gesplit[i] = NULL;
	return (gesplit);
}

/*#include <stdio.h>
int	main()
{
	char	**array;

	array = ft_split("---firulaIs---come-CACA", '-');
	//printf("%d\n", count_array("---firulaIs---come-CACA---", '-'));
	//printf("%d\n", count_array("------", '-'));
	//printf("%d\n", count_array("", '-'));
	//printf("%d\n", count_array("---firulaIs---come-CACA---", '#'));
	//printf("%d\n", count_array("firulaIs---come-CACA---", '-'));
	printf("%s\n", array[0]);
}*/