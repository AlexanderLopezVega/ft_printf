/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:55:48 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/21 10:46:12 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_chars(int n)
{
	size_t	num_chars;

	if (n == 0)
		return (1);
	num_chars = 0;
	if (n < 0)
		++num_chars;
	while (n != 0)
	{
		n /= 10;
		++num_chars;
	}
	return (num_chars);
}

static void	fill_digits_rec(char *str, int n, int *digit)
{
	if (n > -10 && n < 10)
	{
		if (n < 0)
			str[*digit] = '0' + -n;
		else
			str[*digit] = '0' + n;
		++(*digit);
	}
	else
	{
		fill_digits_rec(str, n / 10, digit);
		fill_digits_rec(str, n % 10, digit);
	}
}

char	*ft_itoa(int n)
{
	size_t	num_chars;
	char	*str;
	int		digit;

	num_chars = count_chars(n);
	str = malloc(sizeof(char) * (num_chars + 1));
	if (!str)
		return (NULL);
	digit = 0;
	if (n < 0)
	{
		str[0] = '-';
		digit = 1;
	}
	fill_digits_rec(str, n, &digit);
	str[num_chars] = '\0';
	return (str);
}
