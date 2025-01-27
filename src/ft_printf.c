/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:35 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/27 18:42:47 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j] != '\0')
	{
		while (format[j] != '\0' && format[j] != FORMAT_SPECIFIER_CHAR)
			++j;
		str = ft_substr(format, i, j - i);
		ft_putstr_fd(str, 0);
		free(str);
		while (format[j] != '\0' && format[j] == FORMAT_SPECIFIER_CHAR)
		{
			ft_putarg_fd(format, args, 0);
			++j;
		}
		i = j;
	}
	va_end(args);
	return (0);
}
