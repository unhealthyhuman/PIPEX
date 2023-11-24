/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:57:56 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/14 12:23:55 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
/*returns a pointer to the first occurrence of "c" in the string s*/
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_;
	char	*result;
	char	*s_;

	i = 0;
	result = NULL;
	s_ = (char *) s;
	c_ = (char) c;
	while (s_[i] != '\0' || c_ == '\0')
	{
		if (s_[i] != c_)
			i++;
		else
		{
			result = s_ + i;
			break ;
		}
	}
	return (result);
}
/*#include <stdio.h>
int main(void)
{
	char vaca[100] = "   1234567";
	char *ptr = ft_strchr(vaca, '7');
	if (ptr != NULL)
	{
		printf("'7' found at position %ld.\n", ptr - vaca);
		printf("search character found: %s\n", ptr);
	}
	else
		printf("search character not found\n");
	return (0);
}*/