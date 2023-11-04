CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   init.c \
	   utils.c
OBJS = $(SRCS:.c=.o)

NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re : fclean all