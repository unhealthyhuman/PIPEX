/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:17:57 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/13 12:34:48 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>
int	main()
{
	char	lin[] = "lamamadalamamada";
	char	kin[] = "lamamadalamamada";
	memset(lin + 8, 'o', 2*sizeof(char));
	ft_memset(kin + 8, 'o', 2*sizeof(char));

	printf("OG mem: %s\n", lin);
	printf("My mem: %s\n", kin);
}*/