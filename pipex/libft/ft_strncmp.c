/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:16:48 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/15 10:34:11 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;
	unsigned char	*s1_;
	unsigned char	*s2_;

	i = 0;
	s1_ = (unsigned char *) s1;
	s2_ = (unsigned char *) s2;
	while (i < size && (s1_[i] != '\0' || s2_[i] != '\0'))
	{
		if (s1_[i] < s2_[i])
			return (s1_[i] - s2_[i]);
		if (s1_[i] > s2_[i])
			return (s1_[i] - s2_[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	*ar1 = "aa34";
	char	*ar2 = "aa22";
	int	n = 2;

	printf("%d\n", strncmp(ar1, ar2, n));
	printf("%d\n", ft_strncmp(ar1, ar2, n));

	//if (ft_strncmp(ar1, ar2, 5) == strncmp(ar1, ar2, 5))
	//	printf("nice");
}*/