NAME = libft.a

COMPILER = cc

FLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putnbr_fd.c\
ft_strchr.c\
ft_strdup.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_tolower.c\
ft_toupper.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_substr.c\
ft_strmapi.c\
ft_striteri.c\
ft_strjoin.c\
ft_putnbr_fd.c\
ft_itoa.c\
ft_strtrim.c\
ft_split.c\
printf/ft_printf.c\
printf/ft_putchar.c\
printf/ft_putnbr.c\
printf/ft_putptr.c\
printf/ft_putstr.c\
printf/ft_strlen.c

OBJS := $(SRCS:%.c=%.o)

BSRCS = ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c

BOBJS := $(BSRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@ -I./

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BOBJS)
	ar -rcs $(NAME) $(OBJS) $(BOBJS)

.PHONY: all clean fclean re bonus

