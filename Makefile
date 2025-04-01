NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c operations_1.c operations_2.c operations_3.c utils_1.c utils_2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re