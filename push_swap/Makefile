CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=push_swap.c \
	 push_swap_utils.c \
	 push_swap_parse.c \
	 push_swap_init.c \
	 push_swap_exec.c \
	 push_swap_exec_while.c \
	 push_swap_get_pivot.c \
	 push_swap_sort.c \
	 push_swap_command_push.c \
	 push_swap_command_swap.c \
	 push_swap_command_rotate.c \
	 push_swap_command_reverse_rotate.c
OBJS=$(SRCS:.c=.o)
NAME=push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)