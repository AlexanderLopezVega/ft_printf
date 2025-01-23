/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnode_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:40:24 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 16:56:17 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	ft_getnodes_var(const char *format, size_t *j, va_list args,
		t_list **vars_lst)
{
	while (format[*j] == FORMAT_SPECIFIER_CHAR)
	{
		++(*j);
		if (!ft_lsttrypush(vars_lst, ft_varstr(&(format[*j]), args), &free))
			return (0);
		++(*j);
	}
	return (1);
}
