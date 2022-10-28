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
    t_list  *block_list;
}t_msvar;


void    parse_error(t_msvar *msv);
void    clean_exit(t_msvar *msv);
void    ft_exec(t_msvar *msv);
void    parse(t_msvar *msv);


#endif