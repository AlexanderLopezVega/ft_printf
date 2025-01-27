/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:20:16 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/27 18:17:19 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_count(const double d, size_t *exp_chars, size_t *man_chars)
{
	double	exponent;
	double	mantissa;

	exponent = (double)((long long)d);
	mantissa = d - exponent;
	*exp_chars = 1;
	*man_chars = 0;
	exponent = (long long)(exponent / 10);
	while ((long long)exponent != 0)
	{
		exponent = (long long)(exponent / 10);
		++(*exp_chars);
	}
	if (mantissa != 0.0)
		++(*man_chars);
	while (mantissa != 0.0)
	{
		mantissa *= 10;
		mantissa -= (long long)(mantissa);
		++(*man_chars);
	}
}

static void	ft_fill_exponent(const double d, char *str, const size_t exp_chars)
{
	double	num;
	size_t	i;

	num = d;
	i = 0;
	while (i < exp_chars)
	{
		str[exp_chars - 1 - i] = '0' + ((long long)num) % 10;
		if (d < 0)
			str[exp_chars - 1 - i] = '0' + -((long long)num) % 10;
		num /= 10;
		++i;
	}
}

static void	ft_fill_mantissa(const double d, char *str, const size_t man_chars)
{
	double	num;
	size_t	i;

	if (man_chars == 0)
		return ;
	str[0] = '.';
	num = d;
	i = 0;
	while (i < man_chars - 1)
	{
		num *= 10;
		str[man_chars - 1 - i] = '0' + ((long long)num) % 10;
		if (d < 0)
			str[man_chars - 1 - i] = '0' + -((long long)num) % 10;
		++i;
	}
}

char	*ft_convert_dec(const double d)
{
	size_t	exp_chars;
	size_t	man_chars;
	size_t	sin_chars;
	char	*str;

	ft_count(d, &exp_chars, &man_chars);
	sin_chars = 0;
	if (d < 0)
		sin_chars = 1;
	str = malloc(sizeof(char) * (sin_chars + exp_chars + man_chars + 1));
	if (!str)
		return (NULL);
	if (sin_chars)
		str[0] = '-';
	ft_fill_exponent((long long)(d), str + sin_chars, exp_chars);
	ft_fill_mantissa(d - (long long)(d), str + sin_chars + exp_chars,
		man_chars);
	str[sin_chars + exp_chars + man_chars] = '\0';
	return (str);
}
