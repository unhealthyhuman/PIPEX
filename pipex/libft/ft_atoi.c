/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:17:09 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/22 10:30:40 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_odd_even(int c)
{
	int	caca;

	if (c == 0)
		return (0);
	else if ((c % 2) == 0)
		caca = 0;
	else
		caca = 1;
	return (caca);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (ft_odd_even(minus) == 1)
		num = num * (-1);
	return (num);
}

//% 2 checks if the remainder is 0 it means the num was even

/*#include <stdio.h>
int	main(void)
{
	//char	array[] = "         ---+-u-+768903ab567";
	ft_atoi("\010 9");
	printf("%d", (ft_atoi("\010 9")));
	return (0);
}*/
