#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

typedef struct minishellvariables
{
    char *rline;
    char **rline_split;
}t_msvar;
char	**ft_split(char const *s, char c);

#endif