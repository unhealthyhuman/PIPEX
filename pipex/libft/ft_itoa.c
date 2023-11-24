/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:09:04 by ischmutz          #+#    #+#             */
/*   Updated: 2023/09/19 12:41:55 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	weird_putnbr(char *nb, long long n, int len, int *pos)
{
	if (n < 0)
	{
		nb[0] = '-';
		n = n * (-1);
		(*pos)++;
	}
	if (n >= 0 && n <= 9)
	{
		nb[++(*pos)] = n + '0';
	}
	else if (n >= 10)
	{
		weird_putnbr(nb, n / 10, len, pos);
		weird_putnbr(nb, n % 10, len, pos);
	}
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		len;
	int		pos;

	len = n_len(n);
	pos = -1;
	nb = malloc(len + 1);
	if (nb == NULL)
		return (NULL);
	nb[len] = '\0';
	weird_putnbr(nb, n, len, &pos);
	return (nb);
}

/*static int	n_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n / 10 > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	weird_putnbr(char *nb, long long n, int len)
{
	if (n == 0)
	{
		nb[0] = '0';
		return ;
	}
	if (n < 0)
	{
		nb[0] = '-';
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		nb[len] = n + 48;
		len--;
	}
	else if (n >= 10)
	{
		weird_putnbr(nb, n / 10, len);
		weird_putnbr(nb, n % 10, len);
	}
}

char	*ft_itoa(int n)
{
	char	*nb;
	int	len;

	len = n_len(n);
	nb = malloc(len + 1);
	if (nb == NULL)
		return (NULL);
	nb[len] = '\0';
	weird_putnbr(nb, n, len);
	return (nb);
}*/
// second
/*static size_t	n_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*weird_putnbr(char *nb, long long n, long long buffer, int len)
{
	while (len--)
	{
		nb[len] = n % 10 + '0';
		n = n / 10;
	}
	if (buffer < 0)
	{
		nb[0] = '-';
		if (buffer == -2147483648)
			nb[1] = '2';
	}
	nb[n_len(n)] = '\0';
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	len;
	long long	buffer;

	len = n_len(n);
	buffer = n;
	if (n == -2147483648)
		n = n % 1000000000;
	if (n < 0)
		n = n * (-1)
	nb = (char *)malloc(len + 1);
	if (nb == NULL)
		return (NULL);
	nb = weird_putnbr(nb, n, buffer, len);
	return (nb);
}*/