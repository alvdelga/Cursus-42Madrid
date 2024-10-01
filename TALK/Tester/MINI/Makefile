# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 18:26:31 by alvdelga          #+#    #+#              #
#    Updated: 2024/09/25 18:26:31 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C libft

$(SERVER) : main_server.o error.o includes/minitalk.h
	@$(CC) main_server.o error.o $(LIBS) -o $@
	@printf "\e[38;5;33m✔️ ./$@ successfully built\e[0m\n"

$(CLIENT) : main_client.o error.o includes/minitalk.h
	@$(CC) main_client.o error.o $(LIBS) -o $@
	@printf "\e[38;5;196m🔥 ./$@ successfully built\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;46m💥 .o files deleted\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;226m🧹 Binaries deleted\e[0m\n"

re: fclean all
