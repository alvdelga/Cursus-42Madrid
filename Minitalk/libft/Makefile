# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvdelga <alvdelga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 12:13:06 by alvdelga          #+#    #+#              #
#    Updated: 2024/10/01 12:33:37 by alvdelga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strrchr.c \
       ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_tolower.c \
       ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_toupper.c \
       ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strnstr.c ft_strncmp.c \
	   ft_substr.c ft_strjoin.c ft_itoa.c ft_strmapi.c \
	   ft_strtrim.c ft_split.c ft_striteri.c \
		
 		  
OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)

INCLUDE = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
