/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:34:18 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/17 01:18:53 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;
	
	len = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (len);
}

int ft_print_di(int n)
{
	int		len;
	char	*nbr;

	nbr = ft_itoa(n);
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}

int ft_print_u(unsigned int n)
{
	int		len;
	char	*nbr;

	nbr = ft_utoa(n);
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}

int	ft_print_hex(void *n, char *base)
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
	len = ft_strlen (hex);
	ft_putstr_fd (hex, 1);
	free(hex);
	return (len);
}

int	ft_print_pointer(void *n, char *base)
{
	unsigned long	ntmp;
	int				len;
	char			*hex;

	ntmp = (unsigned long) n;
	len = 3;
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
		hex[--len] = base[ntmp % 16];
		ntmp = ntmp / 16;
	}
	len = ft_strlen (hex);
	ft_putstr_fd (hex, 1);
	free(hex);
	return (len);
}
