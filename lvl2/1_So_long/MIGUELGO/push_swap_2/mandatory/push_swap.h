/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:36:14 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/23 15:55:43 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

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

//atributes.c
void	update_position(t_stack *stack);
t_stack	*max_number(t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	objetives_a(t_stack	*a, t_stack *b);

//ft_split.c
void	ft_free(char **res);
size_t	count_words(char const *s, char c);
char	**write_result(char const *s, char c, char **res);
char	**ft_split(char const *s, char c);
int		all_space(char const *s);

//last_three.c
void	last_three(t_stack **a);
int		number_list(char **list);
long	*free_numbers(char **numbers, int argc);

//move_to_a.c
void	move_to_a(t_stack **a, t_stack **b);
void	objetives_b(t_stack	*a, t_stack *b);
t_stack	*min_number(t_stack *b);
void	last_step(t_stack **a);
void	update_b(t_stack *a, t_stack *b);

//push.c
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b, int c);
void	pb(t_stack **a, t_stack **b, int c);

//push_swap.c
long	*initialize(int argc, char *argv[]);

//push_swap_check.c
int		ft_str_is_numeric(char str);
long	ft_atoi(const char *str);
t_stack	*get_cheapest(t_stack **stack);

//push_swap_utils.c
t_stack	*find_last(t_stack **stack);
void	free_stack(t_stack **stack);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//rotate.c
void	rotate(t_stack **stack);
void	ra(t_stack **a, int c);
void	rb(t_stack **b, int c);
void	rr(t_stack **a, t_stack **b, int c);
void	move_to_upper(t_stack **stack, t_stack *cheapest, char stack_name);

//rotate2.c
void	rotate_two(t_stack **a, t_stack **b, t_stack *cheapest, int c);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack	**a, int c);
void	rrb(t_stack **b, int c);
void	rrr(t_stack **a, t_stack **b, int c);

//sort.c
int		check_sort(t_stack **a);
int		stack_len(t_stack *a);
void	move_to_b(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	update_a(t_stack *a, t_stack *b);

//start.c
char	**get_list(int argc, char **argv);
long	*start(int argc, char **argv);
void	fill_stack(t_stack **stack, int number);
int		check_digit(char *list);
int		check_duplicates(long *numbers);

//swap.c
void	swap(t_stack **stack);
void	sa(t_stack **a, int c);
void	sb(t_stack **b, int c);
void	ss(t_stack **a, t_stack **b, int c);

//BONUS
//bonus_utils.c
int		ft_strncmp(char *s1, char *s2, int n);
void	execute_operation(t_stack **a_bonus, t_stack **b_bonus, char *str);
int		valid_operation(char *str);
void	read_lines(t_stack **a_bonus, t_stack **b_bonus);
void	last_check(t_stack **a);

#endif
