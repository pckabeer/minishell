/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:03 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/06 17:52:29 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	The function read_loop does a clean exit for the program 
*/

void	init_minishell(t_msvar	*msv)
{
	msv->rline = NULL;
	msv->cmd_num = 0;
	msv->num_pipe = 0;
	msv->quote = 0;
	msv->dquote = 0;
	msv->parse_error = 0;
	msv->w_count = 0;
	msv->w_len = 0;
	msv->block_list = NULL;
	msv->env_list = NULL;
	if (msv->output)
		ft_bzero(msv->output, 32767); 
	else
		msv->output = ft_calloc(32767, 1);
	msv->temp = NULL;
	msv->b_temp = NULL;
}

/*
*  The function read_loop  reads line from the command line and then 
*  processes it
* 
*/

int	read_loop(t_msvar *msv)
{
	while (1)
	{
		msv->rline = readline("\033[1;35mminishell $ \033[0m");
		if (msv->rline)
			add_history(msv->rline);
		else
			clean_exit(msv);
		parse(msv);
		if (msv->cmd_num == 7)
			clean_exit(msv);
		if (!msv->parse_error)
			ft_exec(msv);
		else
			parse_error(msv);
		ft_dlstprt(msv->block_list); /// check print
		msv->temp = msv->rline;
		free(msv->temp);
		init_minishell(msv);
	}
}

int	main(int ac, char **av, char **env)
{
	t_msvar	msv;

	(void)ac;
	(void)av;
	init_minishell(&msv);
	load_env(&msv, env);
	read_loop(&msv);
	return (0);
}
