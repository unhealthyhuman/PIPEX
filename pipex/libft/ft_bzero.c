/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:29:22 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/13 12:26:18 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < size)
	{
		*str = '\0';
		str++;
		i++;
	}
}

/*#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char	src[] = "Que pasa larvas";
	
	bzero(src, 10);
	printf("OG bzero: %s\n", src);

	char	src2[] = "Que pasa larvas";

	ft_bzero(src2, 10);
	printf("My bzero: %s\n", src2);
}*/