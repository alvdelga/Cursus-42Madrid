# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leam <leam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 10:07:00 by leam              #+#    #+#              #
#    Updated: 2024/09/28 10:07:03 by leam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de los ejecutables
SERVER_EXEC = server
CLIENT_EXEC = client

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Regla por defecto para compilar ambos ejecutables
all: $(SERVER_EXEC) $(CLIENT_EXEC)

# Compilación del servidor
$(SERVER_EXEC): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER_EXEC) $(SERVER_SRC)

# Compilación del cliente
$(CLIENT_EXEC): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_EXEC) $(CLIENT_SRC)

# Regla para limpiar archivos generados
clean:
	rm -f $(SERVER_EXEC) $(CLIENT_EXEC)

# Regla para forzar la recompilación
re: clean all
