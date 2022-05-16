/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:36:22 by mcesar-d          #+#    #+#             */
/*   Updated: 2022/05/16 10:52:06 by mcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"

int			ft_printf (const char *str, ...);
int			ft_printhex(void *n, char *base);
int			ft_printpointer (void *n);

#endif