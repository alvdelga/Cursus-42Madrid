NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = client.c
SRC_SERVER = server.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER)

clean:
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: clean all

.PHONY: all clean re

