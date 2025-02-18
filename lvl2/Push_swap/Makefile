# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 18:43:05 by alvdelga          #+#    #+#              #
#    Updated: 2025/02/18 12:02:45 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = push_swap

MANDATORY = mandatory/
GNL = gnl/

SRC_FILES = atributes.c \
            last_three.c \
            push.c \
            push_swap.c \
            push_swap_check.c \
            push_swap_utils.c \
            rotate.c \
            rotate2.c \
            start.c \
            ft_split.c \
            move_to_a.c \
            sort.c \
            swap.c

SRC = $(addprefix $(MANDATORY), $(SRC_FILES))
OBJ1 = $(SRC:.c=.o)

all: $(NAME1)

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)

clean:
	rm -f $(OBJ1)

fclean: clean
	rm -f $(NAME1)
re: fclean all
