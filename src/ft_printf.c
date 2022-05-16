/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:32:24 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/17 01:19:39 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_args(const char *str, int i, va_list ap)
{
	int	len;

	len = 1;
	if (str[i] == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (str[i] == '%')
		ft_putchar_fd('%', 1);
	else if (str[i] == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		len = ft_print_di(va_arg(ap, int));
	else if (str[i] == 'p')
		len = ft_print_pointer(va_arg(ap, char *), "0123456789abcdef");
	else if (str[i] == 'u')
		len = ft_print_u(va_arg(ap, unsigned int));
	else if (str[i] == 'x')
		len = ft_print_hex(va_arg(ap, char *), "0123456789abcdef");
	else if (str[i] == 'X')
		len = ft_print_hex(va_arg(ap, char *), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			counter;
	va_list		args;

	va_start (args, str);
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			counter += print_args(str, i + 1, args);
			i = i + 2;
		}
		ft_putchar_fd(str[i], 1);
		i++;
		counter++;
	}
	va_end (args);
	return (counter);
}
