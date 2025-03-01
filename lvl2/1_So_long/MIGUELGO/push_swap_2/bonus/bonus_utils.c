/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:27:50 by miguelgo          #+#    #+#             */
/*   Updated: 2024/04/23 16:19:38 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"
#include "../gnl/get_next_line.h"

void	read_lines(t_stack **a_bonus, t_stack **b_bonus)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return ;
		else if (valid_operation(str) == 0)
		{
			write(2, "Error\n", 6);
			free(str);
			exit(1);
		}
		else
			execute_operation(a_bonus, b_bonus, str);
		free(str);
	}
	if (check_sort(a_bonus) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	valid_operation(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 1 || ft_strncmp(str, "sb\n", 3) == 1)
		return (1);
	else if (ft_strncmp(str, "ss\n", 3) == 1 || ft_strncmp(str, "pa\n", 3) == 1)
		return (1);
	else if (ft_strncmp(str, "pb\n", 3) == 1 || ft_strncmp(str, "ra\n", 3) == 1)
		return (1);
	else if (ft_strncmp(str, "rr\n", 3) == 1 || ft_strncmp(str, "rb\n", 3) == 1)
		return (1);
	else if (ft_strncmp(str, "rra\n", 4) == 1
		|| ft_strncmp(str, "rrb\n", 4) == 1)
		return (1);
	else if (ft_strncmp(str, "rrr\n", 4) == 1)
		return (1);
	else
		return (0);
}

void	last_check(t_stack **a)
{
	if (check_sort(a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	execute_operation(t_stack **a_bonus, t_stack **b_bonus, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 1)
		sa(a_bonus, 0);
	else if (ft_strncmp(str, "sb\n", 3) == 1)
		sb(b_bonus, 0);
	else if (ft_strncmp(str, "ss\n", 3) == 1)
		ss(a_bonus, b_bonus, 0);
	else if (ft_strncmp(str, "pa\n", 3) == 1)
		pa(a_bonus, b_bonus, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 1)
		pb(a_bonus, b_bonus, 0);
	else if (ft_strncmp(str, "ra\n", 3) == 1)
		ra(a_bonus, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 1)
		rb(b_bonus, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 1)
		rr(a_bonus, b_bonus, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 1)
		rra(a_bonus, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 1)
		rrb(b_bonus, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 1)
		rrr(a_bonus, b_bonus, 0);
	else
		return ;
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i < n)
		return (1);
	return (1);
}
