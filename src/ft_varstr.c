/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:20:58 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 16:22:02 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char	*ft_varstr(const char *format, va_list args)
{
	char	c;

	c = *format;
	if (c == 'c')
		return (ft_getchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_getstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_getaddr(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_getdec(va_arg(args, double)));
	else if (c == 'i')
		return (ft_getint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_getdec(va_arg(args, double)));
	else if (c == 'x')
		return (ft_getlowhex(va_arg(args, int)));
	else if (c == 'X')
		return (ft_getupphex(va_arg(args, int)));
	else if (c == '%')
		return (ft_getchar('%'));
	else
		return (NULL);
}
