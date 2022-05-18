/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:19:58 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/18 03:52:14 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(unsigned long long int n, int base)
{
	int	counter;

	counter = 0;
	while (n > 0)
	{
		n = n / base;
		counter++;
	}
	return (counter);
}
