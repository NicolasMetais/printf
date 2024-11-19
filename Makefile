SRCS = 	src/ft_printf.c \

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

compil: $(CC) $(CFLAGS) $(OBJS) -
clean:
	rm -rf *.o
	rm -rf ./src/*.o
	make clean -C ./lib/libft

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./lib/libft

re:	fclean all

.PHONY: all clean fclean re