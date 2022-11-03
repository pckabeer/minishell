/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:09:38 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/03 18:38:40 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void ft_exec_echo_q()
{
    
}

void	ft_exec_echo(t_msvar *msv)
{
	t_dlist	*temp;
	
	temp = msv->block_list->next;
	if(temp->quote == '\'')
	{
		ft_putstr_fd(temp->content, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (temp->quote == '\"')
	{
		//ft_putstr_fd(temp->>content, 1);
		msv->i = 0;
		while (temp->content[msv->i])
		{
			if (temp->content[msv->i] == '$')
			{
				//ft_putstr_fd(ft_getenv(temp->content[msv->i], msv->env), 1);
				temp= temp->next;
			}
			else
			{
				ft_putchar_fd(temp->content[msv->i], 1);
				temp= temp->next;
			}
		}
		ft_putchar_fd('\n', 1);
	}
	ft_putstr_fd(msv->rline+5, 1);
	ft_putchar_fd('\n', 1);
}
