/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:50:29 by apaterno          #+#    #+#             */
/*   Updated: 2024/02/06 10:50:32 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		result;
	t_list	*tmp;

	tmp = lst;
	result = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		result++;
	}
	return (result);
}
