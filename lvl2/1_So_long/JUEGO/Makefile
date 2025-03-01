NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c map.c draw.c gnl/get_next_line.c gnl/get_next_line_utils.c \
       ft_printf/ft_printf.c ft_printf/ft_putstr_fd.c ft_printf/ft_putchar_fd.c \
       ft_printf/ft_putnbr_fd.c ft_printf/ft_putunsigned.c ft_printf/ft_memdir.c game_end.c \
	   check_map.c error.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -I minilibx-linux -L minilibx-linux -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
