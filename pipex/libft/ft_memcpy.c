/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:32:12 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/13 12:01:24 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*src_char;
	char	*dest_char;

	i = 0;
	src_char = (char *) src;
	dest_char = (char *) dest;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (i < size)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>

int main()
{
	char	fil[] = "mooo mooo";
	char	ip[] = "cow cow";

	ft_memcpy(fil, ip, 4);

	//printf("Test: %s\n\n", memcpy(fil, ip, 2));
	printf("Test: %s\n\n", fil);
}*/