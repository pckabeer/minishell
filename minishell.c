
#include "minishell.h"
/*
    The function read_loop does a clean exit for the program 
*/
void cleanexit()
{
    exit(0);
}

void init_minishell(t_msvar *msv)
{
    msv->rline = NULL;
    msv->rline_split = NULL;
}
/*
    The function read_loop  reads line from the command line and then processes it 
*/
int read_loop(t_msvar *msv)
{
    char *temp;
    while(1)
    {
        msv->rline = readline("minishell$");
        if(msv->rline)
        {
            add_history(msv->rline);
            // msv->rline_split = ft_split(msv->rline, ' ');
        }
        else
		{
			ft_putstr_fd("exit\n", 2);
			cleanexit();
		}
        //while(msv->rline_split)
        parse(msv);
        temp = msv->rline;
        free(temp);
    }
}
int main()
{
    t_msvar msv;

    init_minishell(&msv);
    read_loop(&msv);


    return 0;
}

