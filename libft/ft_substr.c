/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:38:43 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/21 16:27:06 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	clamp_len(size_t *len, const unsigned int start,
		const size_t strlen)
{
	if (*len > strlen)
		*len = strlen;
	if (start + *len > strlen)
	{
		if (start < strlen)
			*len = strlen - start;
		else
			*len = 0;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	clamp_len(&len, start, ft_strlen(s));
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
