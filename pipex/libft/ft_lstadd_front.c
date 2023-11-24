/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:32:10 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/21 16:49:35 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		new->next = (*lst);
		(*lst) = new;
	}
}

// If *lsd (ptr to the 1st node(head)) points to nothing
// you point it to the new node.
//If it does point to smt, then you make next into the new head
//Once you've made next into the head, you point the head to the new node
//:)