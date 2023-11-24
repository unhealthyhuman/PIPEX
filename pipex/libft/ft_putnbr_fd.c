/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:27:37 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/18 19:08:05 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = (long long) n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar_fd(nb + 48, fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

/* 
1) long long bc size_t can't be negative
2) nb < 0, to make n positive.
3) nb + 48 bc 48 is the ascii difference to convert a digit into char
4) nb / 10 to go to the first digit (use recursion tree to explain)
5) nb % 10 to go to the last digit
https://recursion.vercel.app/
function fn(nb) {
  var	nb_long;

	nb_long = nb;
	if (nb_long < 0)
	{
		console.log('-');
		nb_long = nb_long * (-1);
	}
	if (nb_long >= 0 && nb_long <= 9)
		console.log(nb_long + 48);
	else if (nb_long >= 10)
	{
		fn(Math.floor(nb_long / 10));
		fn(nb_long % 10);
	}
}
*/