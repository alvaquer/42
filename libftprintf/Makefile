NAME = libftprintf.a
CC = gcc
CFLAGS = -Wextra -Werror -Wall

SRCS = ft_printf.c \
cnvchar.c \
cnvstring.c \
cnvdec.c \
cnvunsigned.c \
cnvhexmin.c \
cnvhexmay.c \
cnvpunter.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 