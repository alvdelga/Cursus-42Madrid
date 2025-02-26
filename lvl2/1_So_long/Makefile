# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:59:34 by alvdelga          #+#    #+#              #
#    Updated: 2025/02/26 18:04:16 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#define WIDTH 1600
#define HEIGHT 1800

NAME = program
CC = gcc
CFLAGS = -Wall -I$(MLX_DIR)
SRC = main2.c
MLX_DIR = minilibx-linux
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext

all: $(MLX_DIR)/libmlx.a $(NAME)

# Primero compila la MiniLibX
$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

# Luego compila el programa
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBS)

clean:
	@rm -f $(NAME)
	@make -C $(MLX_DIR) clean  # Limpia MiniLibX también

re: clean all


