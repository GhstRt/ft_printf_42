NAME    = libftprintf.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_toupper.c ft_putstr.c ft_putchr.c ft_puthex.c ft_strnstr.c ft_print_chr.c ft_print_hex.c ft_print_num.c ft_print_str.c ft_printf.c ft_strfind.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re