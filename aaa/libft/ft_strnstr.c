/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:06:37 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/07 14:20:53 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	e;
	size_t	x;
	char	*big_;
	char	*little_;

	big_ = (char *) big;
	little_ = (char *) little;
	if (little[0] == '\0')
		return (big_);
	i = 0;
	while (big_[i] != '\0')
	{
		x = i;
		e = 0;
		while (big_[i + e] == little_[e] && little_[e] != '\0' && \
		(x + e < size))
		{
			e++;
		}
		if (little_[e] == '\0')
			return (&big_[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	char	*location;
	const char	*haystack = "aaxx";
	const char	*needle = "xx";
	int	LIMIT = 4;

	location = ft_strnstr(haystack, needle, LIMIT);
	if (location == NULL)
		printf("Unable to find '%s' within %d characters of '%s'\n" \
		, needle, LIMIT, haystack);
	else
		printf("Found '%s' within %d characters of '%s'\n" \
		, LIMIT, haystack);
	return (0);
}*/