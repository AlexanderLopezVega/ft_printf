/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:38:39 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 14:59:09 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void	ft_getexponent(const double dec, char *str)
{
	char	*exp_str;

	exp_str = ft_itoa((int)dec);
	if (!exp_str)
		return ;
	ft_strlcpy(str, exp_str, ft_strlen(exp_str) + 1);
	free(exp_str);
}

static void	ft_getmantissa(const double dec, char *str)
{
	size_t	i;
	double	mantissa;

	i = 0;
	mantissa = dec;
	str[i] = '0';
	while (mantissa != (int)mantissa)
	{
		mantissa *= 10;
		str[i] = (int)mantissa % 10 + '0';
		if ((int)mantissa < 0)
			str[i] =(-(int)mantissa) % 10 + '0';
		++i;
	}
}

char	*ft_getdec(const double dec)
{
	size_t	exp_len;
	size_t	man_len;
	char	*str;

	exp_len = ft_exponentlen(dec);
	man_len = ft_mantissalen(dec);
	str = malloc(sizeof(char) * (exp_len + 1 + man_len + 1));
	if (!str)
		return (NULL);
	ft_memset(str, '0', exp_len + 1 + man_len + 1);
	ft_getexponent(dec, str + 0);
	str[exp_len] = '.';
	ft_getmantissa(dec, str + exp_len + 1);
	str[exp_len + 1 + man_len + 1] = '\0';
	return (str);
}
