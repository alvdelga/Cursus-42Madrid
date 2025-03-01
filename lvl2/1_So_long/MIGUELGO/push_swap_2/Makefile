# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelgo <miguelgo@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 18:43:05 by miguelgo          #+#    #+#              #
#    Updated: 2024/04/23 16:32:37 by miguelgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = push_swap
NAME2 = checker

MANDATORY = mandatory/
BONUS = bonus/
GNL = gnl/

SRC1 = $(MANDATORY)atributes.c $(MANDATORY)last_three.c $(MANDATORY)push.c $(MANDATORY)push_swap.c $(MANDATORY)push_swap_check.c $(MANDATORY)push_swap_utils.c $(MANDATORY)rotate.c $(MANDATORY)rotate2.c $(MANDATORY)start.c $(MANDATORY)ft_split.c $(MANDATORY)move_to_a.c $(MANDATORY)sort.c $(MANDATORY)swap.c
SRC2 = $(BONUS)bonus.c $(MANDATORY)atributes.c $(MANDATORY)last_three.c $(MANDATORY)push.c $(MANDATORY)push_swap_check.c $(MANDATORY)push_swap_utils.c $(MANDATORY)rotate.c $(MANDATORY)rotate2.c $(MANDATORY)start.c $(MANDATORY)ft_split.c $(MANDATORY)move_to_a.c $(MANDATORY)sort.c $(MANDATORY)swap.c $(GNL)get_next_line.c $(GNL)get_next_line_utils.c $(BONUS)bonus_utils.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all
