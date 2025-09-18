NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c) \
		$(wildcard tokanize/*.c) \
		$(wildcard memory/*.c) \
		$(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
PATH_LIBFT = libft
LIB_LIBFT = libft/libft.a
all: $(NAME)
$(LIB_LIBFT) :
	@make -C $(PATH_LIBFT)
%.o: %.c
	$(CC) $(CFLAGS) -I$(PATH_LIBFT) -c $< -o $@

$(NAME) : $(OBJS) $(LIB_LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(PATH_LIBFT) -lft -lreadline -o minishell
clean:
	@rm -f $(OBJS)
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re

