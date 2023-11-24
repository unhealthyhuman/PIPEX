/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:46:44 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/13 12:31:08 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t			i;
	unsigned char	*s1_;
	unsigned char	*s2_;

	i = 0;
	s1_ = (unsigned char *) s1;
	s2_ = (unsigned char *) s2;
	while (i < size)
	{
		if (s1_[i] != s2_[i])
			return (s1_[i] - s2_[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main () {
   char str1[100] = "abcdef";
   char str2[100] = "ABCDEF";
   int ret;

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0)
   {
      printf("str2 is less than str1");
   }
   else if(ret < 0)
   {
      printf("str1 is less than str2");
   }
   else
      printf("str1 is equal to str2");
   return(0);
}*/