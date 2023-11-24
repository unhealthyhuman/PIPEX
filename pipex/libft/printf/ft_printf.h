/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:25:52 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/12 12:25:57 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fix, ...);
int		ft_putchar(int c);
int		ft_boringputnbr(long long longie, char *base);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr);
size_t	ft_strlen(const char *s);

#endif