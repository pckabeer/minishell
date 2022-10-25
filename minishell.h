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
    int cmd_num;
}t_msvar;

char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s,int fd);
char	*ft_strjoin(char const *s1, char const *s2);


#endif