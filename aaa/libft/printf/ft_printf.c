/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:06:21 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/16 13:54:25 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_liist(char input, va_list liist)
{
	if (input == 'c')
		return (ft_putchar(va_arg(liist, int)));
	else if (input == 's')
		return (ft_putstr(va_arg(liist, char *)));
	else if (input == 'p')
		return (ft_putptr(va_arg(liist, void *)));
	else if (input == 'd' || input == 'i')
		return (ft_boringputnbr(va_arg(liist, int), "0123456789"));
	else if (input == 'u')
		return (ft_boringputnbr(va_arg(liist, unsigned int), "0123456789"));
	else if (input == 'x')
		return (ft_boringputnbr(va_arg(liist, unsigned int),
				"0123456789abcdef"));
	else if (input == 'X')
		return (ft_boringputnbr(va_arg(liist, unsigned int),
				"0123456789ABCDEF"));
	else if (input == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *fix, ...)
{
	va_list	liist;
	int		keeper;

	keeper = 0;
	if (!fix)
		return (-1);
	va_start(liist, fix);
	while (*fix)
	{
		if (*fix == '%')
		{
			fix++;
			keeper += handle_liist(*fix, liist);
		}
		else
		{
			keeper += write(1, fix, 1);
		}
		fix++;
	}
	va_end(liist);
	return (keeper);
}
