#include "minishell.h"

int parse()
int main()
{
    char *inpt;

    while(1)
    {

        inpt = readline("minishell ");
        add_history(inpt);
       if(!strcmp(inpt,"exit"))
            exit(0);
        printf("%s", inpt);
        printf("\n");
    }
    return 0;
}

