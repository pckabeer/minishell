#include "minishell.h"

void parse_error(t_msvar *msv)
{
    msv->i = 0;
    ft_putstr_fd("\033[0;31mm", 2);
    if(msv->parse_error == 1)
    {
        ft_putstr_fd("minishell: command not found: ", 1);
        while (msv->rline[msv->i] != ' ' && msv->rline[msv->i] != '\0')
            ft_putchar_fd(msv->rline[msv->i++],1);
    }
    else if(msv->parse_error == 2)
        ft_putstr_fd("minishell: parse error near ' ", 1);
    else if(msv->parse_error == 3)
        ft_putstr_fd("minishell: parse error near \" ", 1);
    ft_putchar_fd('\n',1);
        ft_putstr_fd("\033[0m", 2);

}

void clean_exit(t_msvar *msv)
{
    free(msv->rline);
    exit(0);
}