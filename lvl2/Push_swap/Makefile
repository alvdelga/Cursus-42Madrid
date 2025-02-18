# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 18:43:05 by alvdelga          #+#    #+#              #
#    Updated: 2025/02/18 08:31:06 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = push_swap

MANDATORY = mandatory/
GNL = gnl/

SRC1 = $(MANDATORY)atributes.c $(MANDATORY)last_three.c $(MANDATORY)push.c $(MANDATORY)push_swap.c $(MANDATORY)push_swap_check.c $(MANDATORY)push_swap_utils.c $(MANDATORY)rotate.c $(MANDATORY)rotate2.c $(MANDATORY)start.c $(MANDATORY)ft_split.c $(MANDATORY)move_to_a.c $(MANDATORY)sort.c $(MANDATORY)swap.c

OBJ1 = $(SRC1:.c=.o)

all: $(NAME1)

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)

clean:
	rm -f $(OBJ1)

fclean: clean
	rm -f $(NAME1)
re: fclean all
