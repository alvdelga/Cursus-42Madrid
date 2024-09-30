HEADER = ft_printf.h
CC = gcc
CFILES = ft_printf.c\
		 ft_putstr.c\
		 ft_putchar.c\
		 ft_itoa.c\
		 ft_itoa_hex.c\
		 ft_ppointer.c

COBJECTS = $(CFILES:%.c=%.o)
FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all : $(NAME)

%.o : %.c $(HEADER) Makefile
		$(CC) $(FLAGS) -c $<  -o $@ 

$(NAME) : $(COBJECTS) 
		ar -crs $@ $^

clean:
		rm -f $(COBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
