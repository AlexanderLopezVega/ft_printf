/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:35 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 16:42:57 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static t_list	*ft_getvars(const char *format, va_list args)
{
	size_t	i;
	size_t	j;
	t_list	*vars_lst;

	i = 0;
	j = 0;
	vars_lst = NULL;
	while (format[j] != '\0')
	{
		if (!ft_getnodes_var(format, &j, args, &vars_lst)
			|| !ft_getnodes(format, &i, &j, &vars_lst))
			return (NULL);
	}
	return (vars_lst);
}

static void	print_vars(void *str)
{
	ft_putstr_fd(str, 0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_list	*vars_strs;

	va_start(args, format);
	vars_strs = ft_getvars(format, args);
	if (vars_strs)
	{
		ft_lstiter(vars_strs, &print_vars);
		ft_lstclear(&vars_strs, &free);
	}
	va_end(args);
	return (0);
}
