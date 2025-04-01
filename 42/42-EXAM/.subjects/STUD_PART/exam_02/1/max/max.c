/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:57:13 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/17 20:57:13 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	if (len == 0)
		return (0);
	int res = tab[0];
	for (unsigned int i = 0; i < len; i += 1)
	{
		if (res < tab[i])
			res = tab[i];
	}
	return (res);
}
