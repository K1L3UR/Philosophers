NAME = philo
CFLAGS := -MMD -MP -g -pthread -fsanitize=thread -Wall -Wextra -Werror -MMD -MP -g #-fsanitize=thread
CC = clang
SRC = main.c parsing.c routine.c time.c mutex.c init.c
DEP = $(SRC:.c=.d)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
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