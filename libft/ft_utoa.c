/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:07:43 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/18 03:50:40 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	is_zero(int n)
{
	if (n == 0)
		return (1);
	return (0);
}

static int	len_number(unsigned int n)
{
	int					len;
	unsigned long long	l;

	len = 0;
	l = n;
	while (l > 0)
	{
		l = l / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char				*num;
	int					len;
	unsigned int		nbr;

	nbr = n;
	len = len_number(n);
	if (is_zero(n))
		len++;
	if (is_negative(n))
		nbr = n;
	num = (char *)malloc(len + 1);
	if (!num)
		return (0);
	num[len--] = '\0';
	while (len >= 0 && nbr > 0)
	{
		num[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	if (is_zero(n))
		num[len] = '0';
	return (num);
}
