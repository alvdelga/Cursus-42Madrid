/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:48:06 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/22 19:59:33 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Añade el nodo ’new’ al principio de la lista ’lst’.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else if (*lst != NULL)
		new->next = *lst;
	*lst = new;
}
/*int main(void)
{
    t_list *my_list = NULL;

    ft_lstadd_front(&my_list, ft_lstnew((void *)42));
    ft_lstadd_front(&my_list, ft_lstnew((void *)11));
    ft_lstadd_front(&my_list, ft_lstnew((void *)11));
    ft_lstadd_front(&my_list, ft_lstnew((void *)22));

    while (my_list != NULL)
    {
        printf("%d -> ", (int)my_list->content);
        my_list = my_list->next;
    }
    printf("NULL\n");

    return (0);
}*/
