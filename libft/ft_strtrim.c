/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:30:09 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/21 15:06:05 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains_char(const char *str, const char c)
{
	char	*iter;

	iter = (char *)str;
	while (*iter != '\0' && *iter != c)
		++iter;
	return (*iter == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	start = (char *)s1;
	end = start;
	while (*end != '\0')
		++end;
	while (*start != '\0' && contains_char(set, *start))
		++start;
	while (end != start && contains_char(set, *end))
		--end;
	return (ft_substr(start, 0, end - start + 1));
}
