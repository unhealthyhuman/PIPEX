/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:40:18 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/15 13:52:01 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*scans the initial n bytes of the memory area pointed to by s \
for the first instance of c*/
void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c_;
	unsigned char	*result;

	i = 0;
	str = (unsigned char *) s;
	c_ = (unsigned char) c;
	result = NULL;
	while (size > i)
	{
		if (str[i] != c_)
		{
			i++;
		}
		else
		{
			result = str + i;
			break ;
		}
	}
	return (result);
}

// line 29 *str == str[] we dereference the ptr
//"+ i" in "str + i" makes it so I'm not in an infinite loop
/*#include <stdio.h>
int	main(void)
{
	char	src[] = "/|\x12\xff\x09\x42\042\42|\\";
	//char	*ptr = ft_memchr(k, 'a', sizeof(k));
               
	if (memchr(src, '\x42', 2) == ft_memchr(src, '\x42', 2))
	{
		printf("'a' found at position %p\n", ft_memchr(src, '\x42', 2));
		printf("search character found: '\x42'\n");
	}
	else
		printf("search character not found\n");
	return (0);
}*/