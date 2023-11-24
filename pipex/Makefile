NAME = pipex

CC = cc

FLAGS = -Wall -Werror -Wextra

SRCS = pipex.c\
firstborn.c

OBJS := $(SRCS:%c=%.c)

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I./

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re