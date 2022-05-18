/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:32:24 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/18 04:01:42 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_args(const char *str, int i, va_list ap)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str[i + 1] == '%')
		return (ft_putchar('%'));
	else if (str[i + 1] == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_print_di(va_arg(ap, int)));
	else if (str[i + 1] == 'p')
		return (ft_print_pointer(va_arg(ap, char *), "0123456789abcdef"));
	else if (str[i + 1] == 'u')
		return (ft_print_u(va_arg(ap, unsigned int)));
	else if (str[i + 1] == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (str[i + 1] == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else
		return (0);
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
			counter += print_args(str, i, args);
			i++;
		}
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (counter);
}
