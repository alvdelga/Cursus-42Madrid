# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 23:25:06 by alvdelga          #+#    #+#              #
#    Updated: 2024/10/06 23:25:06 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFAGS = -Lft_printf -lftprintf -Llibft -lft

# Mandatory
HEADER = minitalk.h
NAMEC = client
NAMES = server
CFILE = src/client.c\
		src/client_utils.c
SFILE = src/server.c\
		src/server_utils.c
# Bonus
HEADER_B = minitalk_bonus.h
NAMEC_B = client_bonus
NAMES_B = server_bonus
CFILE_B = bonus_src/client_bonus.c\
		bonus_src/client_utils_bonus.c
SFILE_B = bonus_src/server_bonus.c\
		bonus_src/server_utils_bonus.c


all: minitalk

minitalk : library $(NAMES) $(NAMEC) 

$(NAMES) : $(SFILE) $(HEADER)
	$(CC) $(FLAGS) $(SFILE) $(HEADER) $(LFAGS) -o $(NAMES)
	@printf "\e[38;5;33m✔️ ./$@ successfully built\e[0m\n"

$(NAMEC) : $(CFILE) $(HEADER)
	$(CC) $(FLAGS) $(CFILE) $(HEADER) $(LFAGS)  -o $(NAMEC)
	@printf "\e[38;5;196m🔥 ./$@ successfully built\e[0m\n"

bonus : minitalk_bonus

minitalk_bonus : library $(NAMES_B) $(NAMEC_B) 

$(NAMES_B) : $(SFILE_B) $(HEADER_B)
	$(CC) $(FLAGS) $(SFILE) $(HEADER_B) $(LFAGS) -o $(NAMES_B)

$(NAMEC_B) : $(CFILE_B) $(HEADER_B)
	$(CC) $(FLAGS) $(CFILE_B) $(HEADER_B) $(LFAGS)  -o $(NAMEC_B)

library:
	@make -C libft
	@make -C ft_printf
clean:
	make clean -C ft_printf
	make clean -C libft
	@printf "\e[38;5;46m💥 .o files deleted\e[0m\n"

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm -f $(NAMES) $(NAMEC)
	rm -f $(NAMES_B) $(NAMEC_B)
	@printf "\e[38;5;226m🧹 Binaries and .o deleted\e[0m\n"
	

re:	fclean all

.PHONY: all fclean clean re library bonus