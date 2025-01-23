/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:55:51 by alexander         #+#    #+#             */
/*   Updated: 2025/01/21 12:30:11 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	num_bytes;
	size_t	i;
	void	*ptr;

	num_bytes = nmemb * size;
	ptr = malloc(num_bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < num_bytes)
	{
		((unsigned char *)(ptr))[i] = '\0';
		++i;
	}
	return (ptr);
}
