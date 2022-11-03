#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libft/libft.h"

#include <readline/readline.h>
#include <readline/history.h>

/*

*/
typedef struct s_dlist
{
	void			*content;
    char            quote;
    int             len_quote;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;
/*
    cmd_num is the number to find which command eg echo = 1 ...

*/
typedef struct minishellvariables
{
    char    *rline;
    char    **rline_split;
    int     i;
    int     cmd_num;
    int     quote;
    int     dquote;
    int     num_pipe;
    int     parse_error;
    int     word_count;
    int     word_len;    
    t_dlist  *block_list;
    char    *temp;
}t_msvar;


void    parse_error(t_msvar *msv);
void    clean_exit(t_msvar *msv);
void    ft_exec(t_msvar *msv);
void    parse(t_msvar *msv);

t_dlist	*ft_dlstnew(char *data);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
int     ft_dlstsize(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst);
t_dlist	*ft_dlstlast(t_dlist *lst);


#endif