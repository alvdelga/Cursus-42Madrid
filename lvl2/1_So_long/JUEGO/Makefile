NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c map.c draw.c gnl/get_next_line.c gnl/get_next_line_utils.c \
       ft_printf/ft_printf.c ft_printf/ft_putstr_fd.c ft_printf/ft_putchar_fd.c \
       ft_printf/ft_putnbr_fd.c ft_printf/ft_putunsigned.c ft_printf/ft_memdir.c game_end.c \
	   check_map.c error.c key_press.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -lX11 -lXext

all: $(MLX) $(NAME)

# ✅ Compilar MiniLibX si no existe libmlx.a
$(MLX):
	@echo "Compilando MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all
