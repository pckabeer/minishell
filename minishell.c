
#include "minishell.h"

/*
    The function read_loop does a clean exit for the program 
*/
void init_minishell(t_msvar *msv)
{
    msv->rline = NULL;
    msv->rline_split = NULL;
    msv->cmd_num = 0;
    msv->num_pipe = 0;
    msv->quote = 0;
    msv->dquote = 0;
    msv->parse_error = 0;
    msv->word_count = 0;
    msv->word_len = 0;
    msv->block_list = NULL;
}

/*
    The function read_loop  reads line from the command line and then processes it 
*/
int read_loop(t_msvar *msv)
{
    char *temp;
    while(1)
    {
        msv->rline = readline("\033[0;32mminishell $ \033[0m");
        if(msv->rline)
            add_history(msv->rline);
        else
			clean_exit(msv);
        parse(msv);
        if(msv->cmd_num == 7)
            clean_exit(msv);
        if(!msv->parse_error)
            ft_exec(msv);
        else
            parse_error(msv);
        temp = msv->rline;
        free(temp);
        init_minishell(msv);
    }
}

int main()
{
    t_msvar msv;

    init_minishell(&msv);
    read_loop(&msv);
    return 0;
}

