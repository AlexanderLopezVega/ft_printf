/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:35 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 16:37:49 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static int	ft_trypushnode(t_list **lst, char *str)
{
	t_list	*node;

	if (str)
	{
		node = ft_lstnew(str);
		if (node)
		{
			ft_lstadd_back(lst, node);
			return (1);
		}
		free(str);
	}
	ft_lstclear(lst, &free);
	return (0);
}

static int	ft_getvarnodes(const char *format, size_t *j, va_list args,
		t_list **vars_lst)
{
	while (format[*j] == FORMAT_SPECIFIER_CHAR)
	{
		++(*j);
		if (!ft_trypushnode(vars_lst, ft_varstr(&(format[*j]), args)))
			return (0);
		++(*j);
	}
	return (1);
}

static int	ft_getnonvarnodes(const char *format, size_t *i, size_t *j,
		t_list **vars_lst)
{
	*i = *j;
	while (format[*j] != '\0' && format[*j] != FORMAT_SPECIFIER_CHAR)
		++(*j);
	if (*i < *j)
	{
		if (!ft_trypushnode(vars_lst, ft_substr(format, *i, *j - *i)))
			return (0);
		*i = *j;
	}
	return (1);
}

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
		if (!ft_getvarnodes(format, &j, args, &vars_lst)
			|| !ft_getnonvarnodes(format, &i, &j, &vars_lst))
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
