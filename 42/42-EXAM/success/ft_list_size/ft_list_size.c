/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:03:56 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 20:04:59 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


int	ft_list_size(t_list *begin_list)
{
    int len = 0;

    while(begin_list)
    {
        begin_list = begin_list->next;
        len++;
    }
    return (len);
}