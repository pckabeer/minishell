#include "minishell.h"

void ft_exec_echo(t_msvar *msv)
{
    ft_putstr_fd(msv->rline+5, 1);
    ft_putchar_fd('\n', 1);
}

void  ft_exec(t_msvar *msv)
{
    if(msv->cmd_num == 1)
        ft_exec_echo(msv);
}