/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:11:10 by alexander         #+#    #+#             */
/*   Updated: 2025/01/21 12:25:34 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		Copies n bytes from memory area src to memory area dest.  The
///				memory areas must not overlap.  Use ft_memmove if the memory
///				areas do overlap.
/// @param dest	
/// @param src
/// @param n
/// @return		A pointer to dest.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *)(dest))[i] = ((char *)(src))[i];
		++i;
	}
	return (dest);
}
