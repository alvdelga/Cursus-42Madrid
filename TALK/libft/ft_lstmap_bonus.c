/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:49:31 by apaterno          #+#    #+#             */
/*   Updated: 2024/02/06 10:49:37 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmp;
	t_list	*node;

	newlist = NULL;
	tmp = lst;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		node = ft_lstnew(f(tmp->content));
		if (node == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		tmp = tmp->next;
	}
	return (newlist);
}
