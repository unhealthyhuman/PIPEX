/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:14:01 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/17 12:15:53 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

//return funciona pq write returns el n° de bytes written.

/*#include <stdio.h>

int	main()
{
	printf("%zu",ft_putchar('c'));
}*/

/*int	ft_printfc(va_list liist)
{
	char	o;

	o = (char)va_arg(liist, int);
	write(1, &o, 1);
	return (1);
}*/

/*int	main(void)
{
	int	a = 'a';
	printf("%d", ft_putchar(a))
}*/

/*int	ft_printfc(va_list liist)
{
	char	o;

	o = (char)va_arg(liist, int);
	write(1, &o, 1);
	return (1);
}*/
