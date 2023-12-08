/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:43:40 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/16 14:07:11 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsignedputnbr(unsigned long int longie, char *base, int baselen)
{
	char	array[20];
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (longie > 0)
	{
		array[i++] = base[longie % baselen];
		longie /= baselen;
	}
	i--;
	len = i;
	while (i >= 0)
		write(1, &array[i--], 1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	unsigned long	longptrkey;
	char			*base;

	longptrkey = (unsigned long) ptr;
	base = "0123456789abcdef";
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_unsignedputnbr(longptrkey, base, ft_strlen(base)) + 2);
}

/* #include <unistd.h>
#include <stdio.h>
int	main(void)
{
	char	c;
	char	*filip = &c;
	printf("original: %p\n", filip);
	ft_putptr(filip);
}

int	main(void)
{
	unsigned int	aba;

	aba = 42;
	int a= ft_printf("%d\n", -101);
	ft_printf("return = %d\n", a);
	a= printf("%d\n", -101);
	printf("return = %d\n", a);
	//printf("%X", aba);
}  */

//when you attempt to print a NULL pointer using the %p format specifier,
//it will typically print "(nil)" or similar representation.

//has to be printed in hexadecimal format