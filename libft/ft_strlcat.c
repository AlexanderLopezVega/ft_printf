/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:09:59 by alexander         #+#    #+#             */
/*   Updated: 2025/01/20 11:31:31 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	cpy_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	cpy_len = src_len;
	if (cpy_len > size - 1 - dst_len)
		cpy_len = size - 1 - dst_len;
	ft_memcpy(dst + dst_len, src, cpy_len);
	dst[dst_len + cpy_len] = '\0';
	return (dst_len + src_len);
}
