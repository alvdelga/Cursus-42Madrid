# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:59:34 by alvdelga          #+#    #+#              #
#    Updated: 2025/02/26 18:42:06 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I$(MLX_DIR)
SRC = main2.c
OBJS = $(SRC:.c=.o)
MLX_DIR = minilibx-linux
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext

all: $(MLX_DIR)/libmlx.a $(NAME)

# Compila la MiniLibX
$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

# Compila el programa
$(NAME): $(OBJS) so_long.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all