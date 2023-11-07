NAME = philo
CFLAGS := -MMD -MP -g -pthread -lpthread #-Wall -Wextra -Werror -MMD -MP -g
LDFLAGS := -L libft -lft
CC = clang
SRC = main.c parsing.c routine.c time.c
DEP = $(SRC:.c=.d)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft
		$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -rf $(DEP) $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re