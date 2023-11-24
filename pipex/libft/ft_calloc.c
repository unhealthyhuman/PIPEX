/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:24:37 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/21 17:34:49 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buffer;
	size_t	bytesize;

	if (size == 0 || num == 0)
		return (malloc(0));
	bytesize = num * size;
	if (bytesize / num != size || bytesize > 2147483647)
		return (NULL);
	buffer = malloc(bytesize);
	if (buffer != NULL)
	{
		ft_memset(buffer, 0, bytesize);
	}
	return (buffer);
}

//if size is 0 & there are no num(elements) then you malloc 0
//multiplicas num con size para sacar el bytesize
//MATH si bytesize/num no es = size, hay un overflow
// 2147483647 max int, si sobrepasas eso overflow
//si no hay overflow, malloc(bytesize) y guarda en buffer
//si buffer no está vacío, usa memset para poner 0s