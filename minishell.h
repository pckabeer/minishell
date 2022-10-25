#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

typedef struct minishellvariables
{
    char    *rline;
    char    **rline_split;
    int     i;
}t_msvar;

char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s,int fd);

#endif