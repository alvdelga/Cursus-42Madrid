# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 13:17:13 by alvdelga          #+#    #+#              #
#    Updated: 2025/03/02 21:29:21 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = so_long

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I include -I ft_printf -I gnl -I minilibx-linux

# Directorios
SRC_DIR = src
FT_PRINTF_DIR = ft_printf
GNL_DIR = gnl
MLX_DIR = minilibx-linux

# Archivos fuente
SRCS = main.c map.c draw.c game_end.c check_map.c error.c key_press.c utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

# Archivos de ft_printf
FT_PRINTF_SRCS = ft_printf.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_putunsigned.c ft_memdir.c ft_strlen.c
FT_PRINTF_SRCS := $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRCS))

# Archivos de get_next_line
GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_SRCS := $(addprefix $(GNL_DIR)/, $(GNL_SRCS))

# Todos los archivos fuente
SRCS += $(FT_PRINTF_SRCS) $(GNL_SRCS)

# Generar objetos
OBJS = $(SRCS:.c=.o)

# Flags para MiniLibX
MLX_FLAGS = -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lX11 -lXext

# Regla principal
all: $(MLX_DIR)/libmlx.a $(NAME)

# Compilar MiniLibX si no existe
$(MLX_DIR)/libmlx.a:
	@echo "Compilando MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

# Compilar el programa
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Regla para limpiar archivos .o
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

# Regla para limpiar todo
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

# Regla para recompilar
re: fclean all
