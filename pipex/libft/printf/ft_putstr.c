/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:24:57 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/16 16:14:00 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int	main(void)
{
	char	*mamawebo;
	
	mamawebo = "";
	ft_putstr(mamawebo);
	//printf("%s", mamawebo);
} */

/*int	ft_printstr(va_list liist)
{
	char	*a;

	a = (char)va_arg(liist, char *);
	while (a != NULL)
	{
		write(1, a, 1);
		a++;
	}
	return (ft_strlen(a));
}*/
