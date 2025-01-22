/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:35 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/22 17:10:40 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	n;

	va_start(args, format);
	n = ft_count_format_specifiers(format, FORMAT_SPECIFIER_CHAR);
	if (n > 0)
		printf("%d", va_arg(args, int));
	for (unsigned int i = 1; i < n; ++i)
		printf(", %d", va_arg(args, int));
	printf("\n");
	va_end(args);
}

#include <stdio.h>
void	ft_variadic(const unsigned int n, ...)
{
	va_list	args;
	
	va_start(args, n);
	if (n > 0)
		printf("%d", va_arg(args, int));
	for (unsigned int i = 1; i < n; ++i)
		printf(", %d", va_arg(args, int));
	printf("\n");
	va_end(args);
}