/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:19:51 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/27 18:39:49 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stddef.h>

# define FORMAT_SPECIFIER_CHAR '%'

char	*ft_convert_char(const char c);
char	*ft_convert_dec(const double d);
char	*ft_convert_hex(const unsigned long ul, const char *alphabet);
char	*ft_convert_hex_low(const unsigned long ul);
char	*ft_convert_hex_upp(const unsigned long ul);
char	*ft_convert_int(const int i);
char	*ft_convert_ptr(const void *ptr);
char	*ft_convert_str(const char *str);
int		ft_printf(const char *format, ...);
void	ft_putarg_fd(const char *format, va_list args, const int fd);

#endif