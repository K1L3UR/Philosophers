NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_strlen.c \
		ft_strdup.c  \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_itoa.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_strcat.c \
		ft_strjoin3.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	gcc -c -o $@ $< $(FLAGS)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
