/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:33:22 by alvdelga          #+#    #+#             */
/*   Updated: 2025/02/24 11:25:37 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack **stack)
{
	t_stack	*move;

	if (!stack || !(*stack))
		return (NULL);
	move = *stack;
	while (move->next)
		move = move->next;
	return (move);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*move;

	if (!stack || !(*stack))
		return ;
	move = *stack;
	while (move != NULL)
	{
		tmp = move;
		move = move->next;
		free(tmp);
	}
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	copy = (char *)malloc(ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (len--)
	{
		a[i] = s[i + start];
		i++;
	}
	a[i] = '\0';
	return (a);
}
