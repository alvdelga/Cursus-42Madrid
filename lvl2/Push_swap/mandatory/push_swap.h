/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:17:45 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/22 14:19:07 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>   // Define tipos estándar como size_t, ptrdiff_t y NULL
# include <stdio.h>    // Proporciona funciones de entrada y salida estándar como printf y scanf
# include <stdlib.h>   // Contiene funciones para la gestión de memoria, conversión de tipos y control de procesos (malloc, free, atoi, exit)
# include <unistd.h>   // Proporciona funciones de bajo nivel para interactuar con el sistema operativo (write, read, sleep, fork)
# include <limits.h>   // Define constantes con los valores límites de los tipos de datos primitivos (INT_MAX, INT_MIN, CHAR_BIT)
# include <stdbool.h>  // Define los valores booleanos true y false
# include <string.h>   // Proporciona funciones para manipular arrays de caracteres (memset, memcpy, memmove)

typedef struct s_stack
{
	int				number;
	int				cost;
	int				upper;
	int				position;
	int				cheapest;
	struct s_stack	*back;
	struct s_stack	*next;
	struct s_stack	*objetive;
}	t_stack;

// atributes.c
void	update_position(t_stack *stack);
t_stack	*max_number(t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	objetives_a(t_stack	*a, t_stack *b);

// ft_split.c
void	ft_free(char **res);
char	**write_result(char const *s, char c, char **res);
char	**ft_split(char const *s, char c);
int		all_space(char const *s);

// last_three.c
void	last_three(t_stack **a);
int		number_list(char **list);
long	*free_numbers(char **numbers, int argc);

// move_to_a.c
void	move_to_a(t_stack **a, t_stack **b);
void	objetives_b(t_stack	*a, t_stack *b);
t_stack	*min_number(t_stack *b);
void	last_step(t_stack **a);
void	update_b(t_stack *a, t_stack *b);

// push.c
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b, int c);
void	pb(t_stack **a, t_stack **b, int c);

// push_swap.c
long	*initialize(int argc, char *argv[]);

// push_swap_check.c
int		ft_str_is_numeric(char str);
long	ft_atoi(const char *str);
t_stack	*get_cheapest(t_stack **stack);

// push_swap_utils.c
t_stack	*find_last(t_stack **stack);
void	free_stack(t_stack **stack);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// rotate.c
void	rotate(t_stack **stack);
void	ra(t_stack **a, int c);
void	rb(t_stack **b, int c);
void	rr(t_stack **a, t_stack **b, int c);
void	move_to_upper(t_stack **stack, t_stack *cheapest, char stack_name);

// rotate2.c
void	rotate_two(t_stack **a, t_stack **b, t_stack *cheapest, int c);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack	**a, int c);
void	rrb(t_stack **b, int c);
void	rrr(t_stack **a, t_stack **b, int c);

// sort.c
int		check_sort(t_stack **a);
int		stack_len(t_stack *a);
void	move_to_b(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	update_a(t_stack *a, t_stack *b);

// start.c
char	**get_list(int argc, char **argv);
long	*start(int argc, char **argv);
void	fill_stack(t_stack **stack, int number);
int		check_digit(char *list);
int		check_duplicates(long *numbers);

// swap.c
void	swap(t_stack **stack);
void	sa(t_stack **a, int c);
void	sb(t_stack **b, int c);
void	ss(t_stack **a, t_stack **b, int c);

#endif