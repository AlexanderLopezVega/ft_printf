/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:04:54 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:04 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_exponentlen(const double num)
{
	size_t	len;
	int		exponent;

	if (num == 0)
		return (1);
	len = 0;
	exponent = (int)num;
	if (exponent < 0)
		++len;
	while (exponent != 0)
	{
		exponent /= 10;
		++len;
	}
	return (len);
}

size_t	ft_mantissalen(const double num)
{
	double	mantissa;
	size_t	len;

	mantissa = num - (int)num;
	len = 0;
	while (mantissa != 0)
	{
		mantissa *= 10;
		mantissa -= (int)mantissa;
		++len;
	}
	return (len);
}
