/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:12:31 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 13:54:03 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static size_t	ft_countdigits(unsigned long long num)
{
	size_t	num_digits;

	num_digits = 1;
	while (num >= 10)
	{
		num /= 10;
		++num_digits;
	}
	return (num_digits);
}

static void	ft_fillhexstr(char *str, const size_t len, unsigned long long num,
		const char *hex_dic)
{
	size_t	i;

	i = 0;
	str[0] = '0';
	str[1] = 'x';
	ft_memset(str + 2, '0', len);
	str[2 + 1 + len] = '\0';
	while (i < len)
	{
		if (num > 0)
		{
			str[2 + len - i] = hex_dic[num % 16];
			num /= 16;
		}		++i;
	}
}

char	*ft_tohexstr(const unsigned long long num, const char *hex_dic,
		const size_t digits)
{
	size_t len;
	char *str;

	len = ft_countdigits(num);
	if (len < digits)
		len = digits;
	str = malloc(sizeof(char) * (2 + len + 1));
	if (!str)
		return (NULL);
	ft_fillhexstr(str, len, num, hex_dic);
	return (str);
}