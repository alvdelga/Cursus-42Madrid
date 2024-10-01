# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 12:38:16 by alvdelga          #+#    #+#              #
#    Updated: 2024/10/01 12:38:16 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFAGS = -Lft_printf -lftprintf -Llibft -lft

#mandatory
HEADER = minitalk.h
NAMEC = client
NAMES = server
CFILE = src/client.c\
		src/client_utils.c
SFILE = src/server.c\
		src/server_utils.c

all: minitalk

minitalk : library $(NAMES) $(NAMEC) 

$(NAMES) : $(SFILE) $(HEADER) Makefile
	$(CC) $(FLAGS) $(SFILE) $(HEADER) $(LFAGS) -o $(NAMES)

$(NAMEC) : $(CFILE) $(HEADER) Makefile
	$(CC) $(FLAGS) $(CFILE) $(HEADER) $(LFAGS)  -o $(NAMEC)


library:
	@make -C libft
	@make -C ft_printf

clean:
	make clean -C ft_printf
	make clean -C libft

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm -f $(NAMES) $(NAMEC)

re:	fclean all

.PHONY: all fclean clean re library