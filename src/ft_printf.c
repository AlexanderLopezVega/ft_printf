/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:35 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 15:18:40 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

static void	print_lst(void *str)
{
	ft_putstr_fd(str, 0);
}

static void	del_lst(void *str)
{
	free(str);
}

void	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	j;
	t_list	*str_lst;
	char	*str;
	char	c;

	va_start(args, format);
	i = 0;
	j = 0;
	str_lst = NULL;
	c = format[j];
	while (c != '\0')
	{
		if (c == '%')
		{
			if (i < j)
				ft_lstadd_back(&str_lst, ft_lstnew(ft_substr(format, i, j
							- i)));
			++j;
			c = format[j];
			str = NULL;
			if (c == 'c')
				str = ft_getchar(va_arg(args, int));
			else if (c == 's')
				str = ft_getstr(va_arg(args, char *));
			else if (c == 'p')
				str = ft_getaddr(va_arg(args, void *));
			else if (c == 'd')
				str = ft_getdec(va_arg(args, double));
			else if (c == 'i')
				str = ft_getint(va_arg(args, int));
			else if (c == 'u')
				str = ft_getdec(va_arg(args, double));
			else if (c == 'x')
				str = ft_getlowhex(va_arg(args, int));
			else if (c == 'X')
				str = ft_getupphex(va_arg(args, int));
			else if (c == '%')
				str = ft_getchar('%');
			ft_lstadd_back(&str_lst, ft_lstnew(str));
			i = j + 1;
		}
		else if (i == j)
			i = j;
		++j;
		c = format[j];
	}
	if (i < j)
		ft_lstadd_back(&str_lst, ft_lstnew(ft_substr(format, i, j - i)));
	va_end(args);
	if (str_lst)
		ft_lstiter(str_lst, &print_lst);
	ft_lstclear(&str_lst, &del_lst);
}
