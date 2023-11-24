/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:27:23 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/20 16:17:42 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	i;
	size_t	len;

	i = 0;
	while (s1[i] && check_set(s1[i], set))
		i++;
	len = ft_strlen(s1);
	while (len > i && check_set(s1[len - 1], set))
		len--;
	strim = ft_substr(s1, i, len - i);
	return (strim);
}
