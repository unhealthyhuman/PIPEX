/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:31:41 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/16 13:54:48 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_violentputnbr(long long longie2, char *base2, int baselen)
{
	char	array[20];
	int		i;
	int		len;
	int		is_negative;

	len = 0;
	i = 0;
	is_negative = 0;
	if (longie2 < 0)
	{
		write(1, "-", 1);
		longie2 = longie2 * (-1);
		is_negative = 1;
	}
	while (longie2 > 0)
	{
		array[i++] = base2[longie2 % baselen];
		longie2 /= baselen;
	}
	i--;
	len = i;
	while (i >= 0)
		write(1, &array[i--], 1);
	return (len + is_negative + 1);
}

int	ft_boringputnbr(long long longie, char *base)
{
	if (longie == 0)
		return (write(1, "0", 1));
	return (ft_violentputnbr(longie, base, ft_strlen(base)));
}

// Artur's return value test:
/* #include <stdio.h>
int	main(void)
{
	unsigned int	aba;

	aba = 42;
	int a= ft_printf("%d\n", -101);
	ft_printf("return = %d\n", a);
	a= printf("%d\n", -101);
	printf("return = %d\n", a);
	//printf("%X", aba);
} */

/* learn this for exam
void ft_real_expert(long long number, char *base, int base_nbr)
{
	if (number < 0)
	{
		number *= -1;
		write(1, '-', 1);
	}
	ft_expert_putnbr(number, base, base_nbr);
}

void ft_expert_putnbr(long long number, char *base, int base_nbr)
{
	if (number >= base_nbr)
		ft_expert_putnbr(number / base_nbr, base, base_nbr);
	write(1, base[number % base_nbr], 1);
}*/

// convert hex: divide by 16, keep remainder, divide quotient until 0.
// each remainder is a hex value

/* Vorlesung's code lmao
int	ft_shiupint(va_list liist)
{
	int num;

	num = va_arg(liist, int);
	return (num);
}

int	ft_printd(va_list liist)
{
	char	*output;
	int		a;

	a = ft_shiupint(liist);
	output = ft_itoa(a);
	
	while (*output != '\0')
	{
		write(1, output, 1);
		output++;
	}
	return (ft_strlen(output));
}*/

/* Fabian's explanation:
void printf(char *format, ...)
{
	va_list liist;

	va_start(liist, format);
	
	// loop through all format
		// get data type with va_arg

	va_end(liist);
}

void putnbr(unsigned int)
{
	// print
}

void putstr(char *)
{
	// print
}
*/
