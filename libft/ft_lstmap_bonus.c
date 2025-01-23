/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:20:23 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/22 10:49:22 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map_lst;
	t_list	*new_node;
	void	*map_content;

	if (!lst || !f || !del)
		return (NULL);
	map_lst = NULL;
	while (lst)
	{
		map_content = f(lst->content);
		if (map_content)
		{
			new_node = ft_lstnew(map_content);
			if (new_node)
			{
				ft_lstadd_back(&map_lst, new_node);
				lst = lst->next;
				continue ;
			}
			del(map_content);
		}
		ft_lstclear(&map_lst, del);
		return (NULL);
	}
	return (map_lst);
}
