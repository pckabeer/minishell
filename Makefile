
NAME	= minishell
cc		= gcc -lreadline 
CFLAG	= -Wall -Werror -Wextra 
RMFLAG  = -f
SRC		= minishell.c

OBJS	= $(SRC:.c=.o)

all		: $(NAME)

bonus	: all

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean	:
	$(RM) $(RMFLAG) $(OBJS)
fclean	: clean
	$(RM) $(RMFLAG) $(NAME)

re		: fclean all

$(NAME) : $(OBJS)
		@echo "\n"
		@echo "\033[0;32m*************************\n"
		@echo "Compiling minishell...\n"
		@echo "*************************\n"

		@$(cc) $(CFLAG) $(OBJS) -o  $(NAME)
		@echo "\n\033[0mDone !"

.PHONY : all clean fclean re