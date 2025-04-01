/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:57:07 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/23 18:42:56 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*int	main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	*my_list;

	node1.content = "Nodo 1";
	node1.next = &node2;

	node2.content = "Nodo 2";
	node2.next = &node3;

	node3.content = "Nodo 3";
	node3.next = NULL;

	my_list = ft_lstlast(&node1);

	printf("El último nodo es: %s\n", (char *)my_list->content);

	return (0);
}*/
