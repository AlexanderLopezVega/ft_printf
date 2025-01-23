/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:39:52 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 16:49:39 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	ft_getnodes(const char *format, size_t *i, size_t *j, t_list **vars_lst)
{
	*i = *j;
	while (format[*j] != '\0' && format[*j] != FORMAT_SPECIFIER_CHAR)
		++(*j);
	if (*i < *j)
	{
		if (!ft_lsttrypush(vars_lst, ft_substr(format, *i, *j - *i), &free))
			return (0);
		*i = *j;
	}
	return (1);
}
