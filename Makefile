
NAME	= minishell
cc		= gcc -lreadline 
CFLAG	= -Wall -Werror -Wextra -I libft/
RMFLAG  = -f
SRC		= minishell.c parse.c execute.c error.c
LIBFT	= -L libft -lft


OBJS	= $(SRC:.c=.o)

all		: $(NAME)

bonus	: all

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean	:
		@make clean -C libft/
		$(RM) $(RMFLAG) $(OBJS)

fclean	: clean
	$(RM) $(RMFLAG) $(NAME)

re		: fclean all

$(NAME) : $(OBJS)
		@echo "\n"
		@echo "\033[0;32m*************************\n"
		@make -C libft/

		@echo "Compiling minishell...\n"
		@echo "*************************\n"

		@$(cc) $(CFLAG) $(OBJS) -o  $(NAME) $(LIBFT)
		@echo "\n\033[0mDone !"

.PHONY : all clean fclean re