/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:31:18 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/23 18:45:37 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*int	main()
{

	t_list nodo1;
	t_list nodo2;
	t_list nodo3;

	size_t result;

	nodo1.content = "NODO 1";
	nodo1.next = &nodo2;

	nodo2.content = "NODO 2";
	nodo2.next = &nodo3;

	nodo3.content = "NODO 3";
	nodo3.next = NULL;

	result = ft_lstsize(&nodo1);
	printf("%zu\n", result);

	return (0);
}*/
