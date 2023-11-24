/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:51:01 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/21 18:26:22 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*buffer;

	i = 0;
	buffer = lst;
	while (buffer)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

//pones el buffer en head y empiezas a iterar
//como el buffer ya esta en head lo mueves al siguiente ptr
//increase counter
//return counter