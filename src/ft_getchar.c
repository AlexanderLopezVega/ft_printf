/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:33:00 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 12:08:18 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_getchar(const int c)
{
	char	*str;

	str = malloc(sizeof(char) * (1 + 1));
	if (!str)
		return (NULL);
	str[0] = (unsigned char)c;
	str[1] = '\0';
	return (str);
}
