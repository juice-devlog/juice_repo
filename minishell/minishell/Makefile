CC = cc

CFLAGS = -g3 -fsanitize=address
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include
LDFLAGS = -L${HOME}/.brew/opt/readline/lib
LDLIBS = -lreadline



SRCS = ./parse/main.c \
	   ./parse/tokenize.c \
	   ./parse/redirection.c \
	   ./parse/utils.c \
	   ./parse/cmd.c \
	   ./parse/env.c \
	   ./parse/path.c \
	   ./parse/replace.c \
	   ./parse/syntax.c \
	   ./parse/free.c \
	   ./parse/signal.c \
	   ./parse/terminal.c \
	   ./execute/execute.c\
	   ./execute/error.c \
	   ./builtins/builtins.c\
	   ./builtins/builtin_cd.c\
	   ./builtins/builtin_echo.c\
	   ./builtins/builtin_pwd.c\
	   ./builtins/builtin_env.c\
	   ./builtins/ft_strncpy.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft

NAME = minishell

all : $(NAME)

$(NAME) : $(OBJS)

	make all -C $(LIBFT_DIR) 
	$(CC) $(CFLAGS)  $(COMFILE_FLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft $(LDFLAGS) $(LDLIBS)
	@echo "\033[36m" --- 🔹 Compile Compleate 🔹 ---


%.o : %.c
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -c -o $@ $<

clean :
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
