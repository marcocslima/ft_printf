/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:34:18 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/16 11:10:01 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printhex(void *n, char *base)
{
	unsigned long	ntmp;
	int				len;
	char			*hex;

	ntmp = (unsigned long) n;
	len = 1;
	while (ntmp > 0)
	{
		ntmp = ntmp / 16;
		len++;
	}
	ntmp = (unsigned long) n;
	hex = malloc((len) * sizeof(char));
	hex[--len] = '\0';
	while (len > 0)
	{
		hex[--len] = base[ntmp % 16];
		ntmp = ntmp / 16;
	}
	ft_putstr_fd (hex, 1);
	return (ft_strlen (hex));
}

int	ft_printpointer(void *n)
{
	unsigned long	ntmp;
	int				len;
	char			*b_lower;
	char			*hex;

	ntmp = (unsigned long) n;
	len = 3;
	b_lower = "0123456789abcdef";
	while (ntmp > 0)
	{
		ntmp = ntmp / 16;
		len++;
	}
	ntmp = (unsigned long) n;
	hex = malloc((len) * sizeof(char));
	hex[0] = '0';
	hex[1] = 'x';
	hex[--len] = '\0';
	while (len > 2)
	{
		hex[--len] = b_lower[ntmp % 16];
		ntmp = ntmp / 16;
	}
	ft_putstr_fd(hex, 1);
	return (ft_strlen(hex));
}
