/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:20:42 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/27 18:17:02 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_convert_ptr(const void *ptr)
{
	size_t	hex_len;
	char	*hex_str;
	char	*str;

	hex_str = ft_convert_hex_low((unsigned long)(ptr));
	if (!hex_str)
		return (NULL);
	hex_len = ft_strlen(hex_str);
	str = malloc(sizeof(char) * (2 + hex_len + 1));
	if (!str)
	{
		free(hex_str);
		return (NULL);
	}
	str[0] = '0';
	str[1] = 'x';
	ft_strlcat(str, hex_str, 2 + hex_len);
	return (str);
}
