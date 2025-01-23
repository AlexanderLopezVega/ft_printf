/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttrypush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:19 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/23 16:49:26 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lsttrypush(t_list **lst, void *content, void (*del)(void *))
{
	t_list	*node;

	if (content)
	{
		node = ft_lstnew(content);
		if (node)
		{
			ft_lstadd_back(lst, node);
			return (1);
		}
		del(content);
	}
	ft_lstclear(lst, del);
	return (0);
}
