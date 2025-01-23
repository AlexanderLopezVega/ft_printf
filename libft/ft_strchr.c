/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:34:19 by alexander         #+#    #+#             */
/*   Updated: 2025/01/21 14:56:52 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*iter;
	char	found_char;

	iter = (char *)s;
	found_char = 0;
	while (*iter != '\0')
	{
		if (*((unsigned char *)iter) == (unsigned char)c)
			return (iter);
		++iter;
	}
	if ((unsigned char)c == '\0')
		return (iter);
	return (NULL);
}
