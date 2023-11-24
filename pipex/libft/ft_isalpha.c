/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:02:50 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/13 12:11:46 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

static int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}

static int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	return (0);
}

/*int	ft_isalpha(int c)
{
	int result;
	int result2;
	int final_result;

	result = ft_isupper(c); 
	result2 = ft_islower(c); 

	final_result = 0;
	if (result == 1 || result2 == 1)
		final_result = 1;
	return (final_result); 
}*/

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", isalpha('8'));

	printf("Value is %d\n", ft_isupper('a'));
	printf("Value is %d\n\n", isupper('a'));

	printf("Value is %d\n", ft_isupper('X'));
	printf("Value is %d\n\n", isupper('X'));

	printf("Value is %d\n", ft_isupper(';'));
	printf("Value is %d\n\n", isupper(';'));

	printf("Value is %d\n", ft_isupper('\n'));
	printf("Value is %d\n\n", isupper('\n'));
}*/