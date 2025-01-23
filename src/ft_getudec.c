/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getudec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:38:58 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 13:02:29 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static size_t	ft_countchars(double num)
{
	size_t	num_digits;

	num_digits = 1;
	num /= 10;
	while (num <= -10 || num >= 10)
	{
		num /= 10;
		++num_digits;
	}
	if (num != 0)
		++num_digits;
	while (num != 0)
	{
		num *= 10;
		num -= (int)num % 10;
		++num_digits;
	}
	return (num_digits);
}

static void	ft_filldecstr(char *str, double num)
{
	size_t	i;

	i = 0;
	while (num <= -1 || num >= 1)
	{
		num /= 10;
		str[i] = (num - num / 10) + '0';
		++i;
	}
	if (num != 0)
	{
		str[i] = '.';
		++i;
	}
	while (num != 0)
	{
		num *= 10;
		str[i] = num + '0';
		num -= (int)num % 10;
		++i;
	}
}

char	*ft_getudec(const double dec)
{
	size_t	len;
	char	*str;

	len = ft_countchars(dec);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_filldecstr(str, dec);
	return (str);
}
