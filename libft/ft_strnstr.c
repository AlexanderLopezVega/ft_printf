/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:39 by vboxuser          #+#    #+#             */
/*   Updated: 2025/01/22 09:53:34 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i + j] != '\0' && i + j < len)
	{
		while (i + j < len && big[i + j] == little[j] && little[j] != '\0')
			++j;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		else
			j = 0;
		++i;
	}
	return (NULL);
}
