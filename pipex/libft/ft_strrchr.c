/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:09:08 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/14 16:50:33 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_;
	char	*result;
	char	*s_;

	i = 0;
	c_ = (char) c;
	result = NULL;
	s_ = (char *) s;
	if (s_[i] == '\0' && c_ == '\0')
		return (result = s_ + i);
	if (c_ == '\0')
	{
		while (s_[i] != '\0')
			i++;
		return (result = &s_[i]);
	}
	while (s_[i] != '\0')
	{
		if (s_[i] == c_)
			result = s_ + i;
		i++;
	}
	return (result);
}

/*#include <stdio.h>
int	main()
{
	char vaca[100] = "Danny la gente esta muy loca";
	char *ptr = ft_strrchr(vaca, 'a');
	if (ptr != NULL)
	{
		printf("'a' found at position %ld.\n", ptr - vaca);
		printf("search character found: %s\n", ptr);
	}
	else
		printf("search character not found\n");
	return (0);
}*/

	/*while (s_[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s_[i] != 'c_')
			i--;
		else
		{
			result = s_ + i;
			break;
		}
	}
	return (result);*/