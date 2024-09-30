CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFAGS = -Lft_printf -lftprintf -Llibft -lft

#mandatory
HEADER = inc/minitalk.h
NAMEC = client
NAMES = server
CFILE = src/client.c\
		src/client_utils.c
SFILE = src/server.c\
		src/server_utils.c
#bonus
HEADER_B = inc/minitalk_bonus.h
NAMEC_B = client_bonus
NAMES_B = server_bonus
CFILE_B = src_bonus/client_bonus.c\
		src_bonus/client_utils_bonus.c
SFILE_B = src_bonus/server_bonus.c\
		src_bonus/server_utils_bonus.c


all: minitalk

minitalk : library $(NAMES) $(NAMEC) 

$(NAMES) : $(SFILE) $(HEADER) Makefile
	$(CC) $(FLAGS) $(SFILE) $(HEADER) $(LFAGS) -o $(NAMES)

$(NAMEC) : $(CFILE) $(HEADER) Makefile
	$(CC) $(FLAGS) $(CFILE) $(HEADER) $(LFAGS)  -o $(NAMEC)

bonus : minitalk_bonus

minitalk_bonus : library $(NAMES_B) $(NAMEC_B) 

$(NAMES_B) : $(SFILE_B) $(HEADER_B) Makefile
	$(CC) $(FLAGS) $(SFILE) $(HEADER_B) $(LFAGS) -o $(NAMES_B)

$(NAMEC_B) : $(CFILE_B) $(HEADER_B) Makefile
	$(CC) $(FLAGS) $(CFILE_B) $(HEADER_B) $(LFAGS)  -o $(NAMEC_B)

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
	rm -f $(NAMES_B) $(NAMEC_B)
	

re:	fclean all

.PHONY: all fclean clean re bonus library