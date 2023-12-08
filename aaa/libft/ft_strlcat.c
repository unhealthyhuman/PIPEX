/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:15:16 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/22 10:30:35 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0' && (size > i))
	{
		i++;
	}
	return (ft_strlcpy(&dest[i], src, size - i) + i);
}

// strlcpy + i pq strlcpy returns length of src y necesito return dest + src

/*#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	src[] = "larvas";
	char	dest[99] = "hola";

	strlcat(dest, src, 11);
	printf("OG strlcat: %s\n", dest);

	char	src2[] = "larvas";
	char	dest2[99] = "hola";

	ft_strlcat(dest2, src2, 11);
	printf("My strlcat: %s\n", dest2);
}*/