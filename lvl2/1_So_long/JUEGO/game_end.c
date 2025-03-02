/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:10:26 by alvdelga          #+#    #+#             */
/*   Updated: 2025/03/02 06:48:33 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void game_over_banner(void)
{
    ft_printf("\n\n%s", SLOW_BLINK);  // Parpadeo lento
    ft_printf("%s╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗\n", F_L_YELLOW);
    ft_printf("%s║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝\n", F_L_GREY);
    ft_printf("%s╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═%s\n", F_L_MAGENTA, RST);
    ft_printf("%s\n", RST);  // Resetear estilos para no afectar el resto del terminal
}
