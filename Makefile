# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Project name
NAME = push_swap

# Source files
SRCS = push_swap.c \
       operations1.c \
       operations2.c \
       operations3.c \
       operations4.c \
       utils1.c \
       utils2.c \
       utils3.c \
       utils4.c \
       sort1.c \
       sort2.c \
       sort3.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = push_swap.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re