/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:30:21 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 17:35:55 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
        return ;
    t_list *curr = *begin_list;
    if((cmp)(curr->data, data_ref) == 0)
    {
        *begin_list = curr->next;
        free(curr);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    curr = *begin_list;
    ft_list_remove_if(&curr->next, data_ref, cmp);
}

// Función para comparar enteros (devuelve 0 si son iguales)
int cmp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

// Función para crear un nuevo nodo
t_list *create_elem(void *data)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new)
        return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

// Función para imprimir la lista
void print_list(t_list *head)
{
    while (head)
    {
        printf("%d -> ", *(int *)(head->data));
        head = head->next;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void free_list(t_list *head)
{
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    // Crear una lista con los valores 1 -> 2 -> 3 -> 2 -> 4 -> NULL
    int values[] = {1, 2, 3, 2, 4};
    t_list *head = create_elem(&values[0]);
    head->next = create_elem(&values[1]);
    head->next->next = create_elem(&values[2]);
    head->next->next->next = create_elem(&values[3]);
    head->next->next->next->next = create_elem(&values[4]);

    printf("Lista original:\n");
    print_list(head);

    // Valor a eliminar (todos los nodos con valor 2)
    int target = 2;
    ft_list_remove_if(&head, &target, cmp);

    printf("Lista después de eliminar %d:\n", target);
    print_list(head);

    // Liberar la memoria restante
    free_list(head);
    return 0;
}