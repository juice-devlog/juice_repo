CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=push_swap.c \
	 ./utils/push_swap_utils.c \
	 ./init/push_swap_parse.c \
	 ./init/push_swap_init.c \
	 ./sort/push_swap_exec.c \
	 ./sort/push_swap_exec_while.c \
	 ./sort/push_swap_get_pivot.c \
	 ./sort/push_swap_sort.c \
	 ./commands/push_swap_command_push.c \
	 ./commands/push_swap_command_swap.c \
	 ./commands/push_swap_command_rotate.c \
	 ./commands/push_swap_command_reverse_rotate.c \
	 test.c
OBJS=$(SRCS:.c=.o)
INC=./include
NAME=push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re : fclean all