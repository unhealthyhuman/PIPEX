/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:34:53 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/13 14:52:06 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*src_;
	char	*dest_;

	src_ = (char *) src;
	dest_ = (char *) dest;
	if (dest_ <= src_ || dest_ > src_ + size)
		return (ft_memcpy(dest, src, size));
	while (size >= 1)
	{
		dest_[size - 1] = src_[size - 1];
		size--;
	}
	return (dest_);
}

/*#include <stdio.h>
int	main()
{}
	char	s1[100] = "pirulein";
	char	s2[100] = "pirata";

	printf("String 1 before memmove: %s\n", s1);

	memmove(s1, s2, sizeof(s2));

	printf("String 1 after memmove: %s\n", s1);

	return (0);
}*/