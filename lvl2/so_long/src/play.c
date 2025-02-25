/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelgo <miguelgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:50:52 by miguelgo          #+#    #+#             */
/*   Updated: 2024/05/05 20:59:22 by miguelgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_bart2(t_map ***final_map, t_atrib *atribs)
{
	if ((**final_map)->player->content == 'C')
		atribs->coins--;
	if (atribs->coins == 0)
		atribs->escape = 1;
	if ((**final_map)->player->content == 'E' && atribs->coins == 0)
		victory();
}

void	print_moves(int a, t_atrib *atribs)
{
	if (a == 1)
		ft_printf("Moves: %i\n", atribs->moves++);
}

void	move_bart(t_map ***final_map, char c, t_atrib *atribs)
{
	int	a;
	int	d;

	d = 0;
	a = 1;
	if ((**final_map)->player->content != 'E')
		(**final_map)->player->content = '0';
	if (c == 'l' && ((**final_map)->player->left->content != '1'))
		(**final_map)->player = (**final_map)->player->left;
	else if (c == 'd' && ((**final_map)->player->right->content != '1'))
		(**final_map)->player = (**final_map)->player->right;
	else if (c == 's' && ((**final_map)->player->down->content != '1'))
		(**final_map)->player = (**final_map)->player->down;
	else if (c == 'w' && ((**final_map)->player->up->content != '1'))
		(**final_map)->player = (**final_map)->player->up;
	else
		a = 0;
	move_bart2(final_map, atribs);
	if ((**final_map)->player->content == 'E')
		d = 1;
	(**final_map)->player->content = 'P';
	render(final_map, atribs);
	if (d == 1)
		(**final_map)->player->content = 'E';
	print_moves(a, atribs);
}

int	key_handler(int keycode, t_atrib *atribs)
{
	if (keycode == A)
		move_bart(atribs->final_map, 'l', atribs);
	if (keycode == D)
		move_bart(atribs->final_map, 'd', atribs);
	if (keycode == S)
		move_bart(atribs->final_map, 's', atribs);
	if (keycode == W)
		move_bart(atribs->final_map, 'w', atribs);
	if (keycode == ESC)
		error_cases("Too dificult for you brah");
	return (1);
}
