/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:08:52 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/29 09:48:36 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_getarg(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_convert_char(va_arg(args, int)));
	else if (*format == 's')
		return (ft_convert_str(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_convert_ptr(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_convert_int(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_convert_dec(va_arg(args, double)));
	else if (*format == 'x')
		return (ft_convert_hex_low(va_arg(args, unsigned int)));
	else if (*format == 'X')
		return (ft_convert_hex_upp(va_arg(args, unsigned int)));
	else if (*format == '%')
		return (ft_convert_char('%'));
	return (NULL);
}

void	ft_putarg_fd(const char *format, va_list args, const int fd)
{
	char	*str;

	str = ft_getarg(format, args);
	if (str)
	{
		ft_putstr_fd(str, fd);
		free(str);
	}
}
