/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:36:22 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/18 03:53:11 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_str(char *str);
int	ft_print_di(int n);
int	ft_print_u(unsigned int n);
int	ft_print_hex(unsigned long long int n, char *base);
int	ft_print_pointer(void *n, char *base);

#endif