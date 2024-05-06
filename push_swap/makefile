#VARIABLES
NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
HEADER = push_swap.h

#ARCHIVOS
FILES = index.c \
        actions_utils.c \
        actions.c \
        actions1.c \
        actions2.c \
        ft_split.c \
        moves.c \
        moves2.c \
        push_swap_utils.c \
        save_params.c \
        sort_main.c \
		sort_positions.c \
		sort_utils.c \

FILES_BONUS = bonus.c \
        bonus_utils.c \
        actions_utils.c \
        actions.c \
        actions1.c \
        actions2.c \
        ft_split.c \
        moves.c \
        moves2.c \
        get_next_line.c \
        get_next_line_utils.c \
        push_swap_utils.c \
        save_params.c \
        sort_main.c \
		sort_positions.c \
		sort_utils.c \

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
	$(CC) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)

#ENCARGADO DE HACER LA PARTE DE LIMPIEZA TANTO EN ESTA CARPETA COMO EN FT_PRINTF
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus