/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:36:22 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/15 20:56:04 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"

int			ft_printf (const char *str, ...);
char		*dec_to_hex(int n);
int			ft_printpointer (void *n);
char		*dec_to_hex (int n);

#endif