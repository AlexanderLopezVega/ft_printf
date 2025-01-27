/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:20:25 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/27 18:20:08 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_count_chars(unsigned long num, unsigned int *num_chars)
{
	*num_chars = 1;
	if (num > 0)
	{
		num /= 16;
		while (num > 0)
		{
			num /= 16;
			++(*num_chars);
		}
	}
}

char	*ft_convert_hex(const unsigned long ul, const char *alphabet)
{
	unsigned long	num;
	unsigned int	num_chars;
	unsigned int	i;
	char			*str;

	num = ul;
	ft_count_chars(num, &num_chars);
	str = malloc(sizeof(char) * (num_chars + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < num_chars)
	{
		str[num_chars - 1 - i] = alphabet[num % 16];
		num /= 16;
		++i;
	}
	return (str);
}

char	*ft_convert_hex_low(const unsigned long ul)
{
	return (ft_convert_hex(ul, "0123456789abcdef"));
}

char	*ft_convert_hex_upp(const unsigned long ul)
{
	return (ft_convert_hex(ul, "0123456789ABCDEF"));
}
