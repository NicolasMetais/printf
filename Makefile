SRCS = 	src/ft_printf.c \
		src/ft_char_manager.c \
		src/ft_condition.c \
		src/ft_hexa_manager.c \
		src/ft_itoa_unsigned.c \
		src/ft_int_manager.c \
		src/ft_hexa_convert.c \


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = ./lib/libft/libft.a

all: $(NAME) lib

$(NAME): $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	make --silent -C ./lib/libft

clean:
	rm -rf *.o
	rm -rf ./src/*.o
	make clean -C ./lib/libft

c:
	cc -Wall -Werror -Wextra ./src/ft_printf.c ./src/ft_int_manager.c ./src/ft_itoa_unsigned.c ./src/ft_hexa_manager.c ./lib/libft/src/ft_itoa.c ./lib/libft/src/ft_putchar_fd.c ./lib/libft/src/ft_toupper.c ./lib/libft/src/ft_memmove.c ./src/ft_char_manager.c ./src/ft_condition.c ./lib/libft/src/ft_strlen.c ./lib/libft/src/ft_strnstr.c ./lib/libft/src/ft_calloc.c ./lib/libft/src/ft_memcpy.c ./lib/libft/src/ft_strncmp.c -g3

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./lib/libft

re:	fclean all

.PHONY: all compil clean fclean re