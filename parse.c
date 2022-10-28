#include "minishell.h"

void parse_quote_block(t_msvar *msv)
{
            msv->quote++; 
            msv->i++;
            while(msv->rline[msv->i] != '\'' && msv->rline[msv->i] != '\0')
            {
                msv->word_len++;
                msv->i++;
            }
            if(msv->rline[msv->i] == '\'')
               {
                    msv->quote++;     
                    msv->word_count++;
               }
            if(msv->quote % 2 != 0)
                msv->parse_error = 2;
}

void parse_dquote_block(t_msvar *msv)
{
            msv->dquote++; 
            msv->i++;
            while(msv->rline[msv->i] != '"' && msv->rline[msv->i] != '\0')
            {
                msv->word_len++;
                msv->i++;
            }
            if(msv->rline[msv->i] == '"')
                msv->dquote++;     
            if(msv->dquote % 2 != 0)
                msv->parse_error = 3;
}

void parse_split_elements(t_msvar *msv)
{
    if(msv->parse_error)
        return;
    while(msv->rline[msv->i++])
    {
        //printf("msv->rline[%d] = %c \n", msv->quote, msv->rline[msv->i]);
        if(msv->rline[msv->i] == '\'')
            parse_quote_block(msv);
        else if(msv->rline[msv->i] == '"')
            parse_dquote_block(msv);
        if(msv->parse_error == 1)
            break;
        msv->word_len = 0;
    }
    ft_putstr_fd("qcount = ", 1);
    ft_putnbr_fd(msv->quote+msv->dquote, 1);
    ft_putchar_fd('\n',1);
}

/*
     The function parse_cmd_check checks which is the command being used .eg : echo , ls etc
*/
void parse_cmd_check(t_msvar *msv)
{
    if(!ft_strncmp("echo",msv->block_list->content,4)&& strlen(msv->block_list->content) == 4)
    msv->cmd_num = 1;
    else if(!ft_strncmp("cd",msv->block_list->content,2)&& strlen(msv->block_list->content) == 2)
    msv->cmd_num = 2;
    else if(!ft_strncmp("pwd",msv->block_list->content,3)&& strlen(msv->block_list->content) == 3)
    msv->cmd_num = 3;
    else if(!ft_strncmp("export",msv->block_list->content,6)&& strlen(msv->block_list->content) == 6)
    msv->cmd_num = 4;
    else if(!ft_strncmp("unset",msv->block_list->content,5)&& strlen(msv->block_list->content) == 5)
    msv->cmd_num = 5;
    else if(!ft_strncmp("env",msv->block_list->content,3)&& strlen(msv->block_list->content) == 3)
    msv->cmd_num = 6;
    else if(!ft_strncmp("exit",msv->block_list->content,4)&& strlen(msv->block_list->content) == 4)
    msv->cmd_num = 7;
    else
    msv->parse_error = 1;
}

void parse_cmd_init(t_msvar *msv)
{    
    if(msv->parse_error)
        return;
    if( msv->cmd_num == 1)
        msv->i = 4;
    else if(msv->cmd_num == 2)
        msv->i = 2;
    else if(msv->cmd_num == 3)
        msv->i = 3;
    else if(msv->cmd_num == 4)
        msv->i = 6;
    else if(msv->cmd_num == 5)
        msv->i = 5;
    else if(msv->cmd_num == 6)
        msv->i = 3;
}

 void parse(t_msvar *msv)
 {
    int str_len;

    str_len = ft_strchr(msv->rline, ' ') - msv->rline;
    msv->block_list = ft_lstnew(ft_substr(msv->rline, 0, str_len));
    parse_cmd_check(msv);
    parse_cmd_init(msv);
    parse_split_elements(msv);
 }
