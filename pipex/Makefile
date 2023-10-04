CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c \
	   pipex_process.c \
	   pipex_free_error.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft

NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all