#include "minishell.h"

void parse_error(t_msvar *msv, int err_type)
{
    msv->i = 0;
    if(err_type == 1)
    {
        ft_putstr_fd("minishell: command not found: ", 1);
        while (msv->rline[msv->i] != ' ' && msv->rline[msv->i] != '\0')
            ft_putchar_fd(msv->rline[msv->i++],1);
    }
    else if(err_type == 2)
        ft_putstr_fd("minishell: parse error near ' ", 1);
    ft_putchar_fd('\n',1);
}

void clean_exit(t_msvar *msv)
{
    free(msv->rline);
    exit(0);
}
