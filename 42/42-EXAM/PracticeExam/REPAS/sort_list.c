/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:20:03 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 16:57:17 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *res;
    int temp;
    int flag = 1;

    while (flag)
    {
        flag = 0;
        res = lst;
        while(res->next)
        {
            if(!(cmp)(res->data, res->next->data))
            {
                temp = res->data;
                res->data = res->next->data;
                res->next->data = temp;
                flag = 1;
            }
            res = res->next;
        }
    }
    return (lst);
}

int ascending(int a, int b) {
    return (a > b);
}

// Función para crear un nuevo nodo de la lista
t_list *create_node(int value) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Función para imprimir la lista
void print_list(t_list *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void free_list(t_list *head) {
    t_list *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    // Creación de la lista: 4 -> 2 -> 7 -> 1 -> 5 -> NULL
    t_list *head = create_node(4);
    head->next = create_node(2);
    head->next->next = create_node(7);
    head->next->next->next = create_node(1);
    head->next->next->next->next = create_node(5);

    printf("Lista original:\n");
    print_list(head);

    // Ordenar la lista
    head = sort_list(head, ascending);

    printf("\nLista ordenada:\n");
    print_list(head);

    // Liberar memoria
    free_list(head);

    return 0;
}