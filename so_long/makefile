#VARIABLES
NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
HEADER = so_long.h
PRINTF_PATH = ft_printf/libftprintf
LIBFT_LIBFT = $(PRINTF_PATH)/libftprintf.a
MLX_PATH = ./MLX42/
MLX_LIBFT = ./MLX42/lib/MLX42/MLX42.h 
CCMLX = ./MLX42/build/libmlx42.a -ldl -lglfw -I include -lglfw -L "/Users/alvaquer/.brew/opt/glfw/lib/" -pthread -lm

#ARCHIVOS
FILES = index.c \
        get_next_line.c \
        get_next_line_utils.c \
        check_map.c \
        check_map2.c \
        init.c \
        mlx_loop.c \
        move.c \
        start_window.c \
        so_long_utils.c \
        aux_functions.c \

FILES_BONUS = index.c \
		get_next_line.c \
		get_next_line_utils.c \
		check_map_bonus.c \
		check_map2.c \
		init.c \
		mlx_loop.c \
		bonus.c \
		start_window.c \
		so_long_utils.c \
		aux_functions.c \

#CREA LOS ARCHIVOS OBJETO
OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

#COMPILA LOS ARCHIVOS
all: $(NAME)

bonus: $(NAME_BONUS)

$(OBJS) $(OBJS_BONUS): Makefile

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(PRINTF_PATH)
	mkdir -p $(MLX_PATH)/build
	cmake -B $(MLX_PATH)/build $(MLX_PATH)
	make -C $(MLX_PATH)/build
	$(CC) $(OBJS) $(LIBFT_LIBFT) $(CCMLX) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(PRINTF_PATH)
	mkdir -p $(MLX_PATH)/build
	cmake -B $(MLX_PATH)/build $(MLX_PATH)
	make -C $(MLX_PATH)/build
	$(CC) $(OBJS_BONUS) $(LIBFT_LIBFT) $(CCMLX) -o $(NAME_BONUS)

#ENCARGADO DE HACER LA PARTE DE LIMPIEZA TANTO EN ESTA CARPETA COMO EN FT_PRINTF
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(PRINTF_PATH) clean
	rm -rf $(MLX_PATH)build/

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(PRINTF_PATH)
	rm -rf $(MLX_PATH)build/

re: fclean all

.PHONY: all clean fclean re bonus