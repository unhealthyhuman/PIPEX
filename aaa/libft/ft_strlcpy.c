/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:50:42 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/13 16:53:49 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	while (src[i] != '\0' && size > i + 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > i)
		dest[i] = '\0';
	while (src[e] != '\0')
	{
		e++;
	}
	return (e);
}

/*#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	src[] = "Vale";
	char	dest[100] = "Hola";

	//strlcpy(dest + 4, src, 4);
	printf("OG strlcpy: %s\n%zu\n\n", dest, \
	(dest, "aasdjj;s;sa", 100));

	char	src2[] = "Vale";
	char	dest2[100] = "Hola";

	//ft_strlcpy(dest2, src2, 9);
	 printf("My strlcpy: %s\n%zu\n\n", dest2, \
	 ft_strlcpy(dest2, "aasdjj;s;sa", 100));
}*/