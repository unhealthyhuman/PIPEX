/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:09:57 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/14 17:30:27 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dupli;
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dupli = (char *) malloc (i + 1);
	if (!dupli)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dupli[i] = src[i];
		i++;
	}
	dupli[i] = '\0';
	return (dupli);
}

// (!dupli) == (dupli = NULL) this protects the malloc return
/*#include <stdio.h>
int	main()
{
	char	mon[] = "hola";
	char *novi;
	
	novi = ft_strdup(mon);	
	printf("%s ", novi);
}*/