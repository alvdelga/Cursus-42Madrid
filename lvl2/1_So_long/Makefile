# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:59:34 by alvdelga          #+#    #+#              #
#    Updated: 2025/02/25 16:41:36 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#define WIDTH 1600
#define HEIGHT 1800

NAME = program
CC = gcc
CFLAGS = -Wall -I$(MLX_DIR)  # Agregamos -I$(MLX_DIR) para que encuentre mlx.h
SRC = main2.c
MLX_DIR = minilibx
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBS)

clean:
	@rm -f $(NAME)

re: clean all

