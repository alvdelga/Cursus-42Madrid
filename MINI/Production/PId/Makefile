# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leam <leam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 11:56:01 by alvdelga          #+#    #+#              #
#    Updated: 2024/09/30 12:39:17 by leam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del compilador
CC = gcc

# Opciones de compilación
CFLAGS = -I../../../ft_printf/

# Nombre del archivo fuente y ejecutable
SRC = pid.c
OBJ = $(SRC:.c=.o)
EXEC = pidpid

# Biblioteca a enlazar
LIB = ../../../ft_printf/libftprintf.a

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) -o $(EXEC)

# Regla para compilar el archivo objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJ) $(EXEC)

# Regla para limpiar todo (incluyendo archivos de objeto y el ejecutable)
fclean: clean
	rm -f $(LIB)

# Regla para recompilar todo
re: fclean all

.PHONY: all clean fclean re
