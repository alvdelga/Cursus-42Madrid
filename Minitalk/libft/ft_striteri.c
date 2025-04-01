/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:39:08 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/18 22:47:48 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int,
char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
/*void root13(unsigned int y, char *c)
{
	while (*c)
	{
		if (*c <= 'M')
			*c += 13;
		else if (*c > 'M')
			*c -= 13;
		c++;
	}
}
int main(void)
{
	char str [] = "PACOPAQUITO";
	ft_striteri(str, (void *)root13);
	printf("%s", str);
	return (0);
}*/
