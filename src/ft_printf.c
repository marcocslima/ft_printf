/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:32:24 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/16 10:51:35 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int print_args(const char *str, int i, va_list ap)
{
	int len;
	
	len = 1;
	if (str[i] == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (str[i] == '%')
		ft_putchar_fd('%', 1);
	else if (str[i] == 's')
		len = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (str[i] == 'd' || str[i] == 'i')
		len = ft_putstr_fd(ft_itoa(va_arg(ap, int)),1);
	else if (str[i] == 'p')
		len = ft_printpointer(va_arg(ap, char *));
	else if (str[i] == 'u')
		len = ft_putstr_fd(ft_utoa(va_arg(ap, unsigned int)), 1);
	else if (str[i] == 'x')
		len = ft_printhex(va_arg(ap, char *), "0123456789abcdef");
	else if (str[i] == 'X')
		len = ft_printhex(va_arg(ap, char *), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int counter;
	va_list ap;
	va_start (ap, str);

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i+1]))
		{
			counter += print_args(str, i + 1, ap);
			i = i + 2;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		counter++;
	}
	va_end (ap);
	return (counter);
}
