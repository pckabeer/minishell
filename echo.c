/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:09:38 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/03 19:41:39 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_exec_echo_q(t_dlist *temp)
{
	ft_putstr_fd(temp->content, 1);
	ft_putchar_fd('\n', 1);
	return ;
}


void	ft_exec_echo_dq(t_dlist *temp)
{		
	i = 0;
	while (temp->content[i])
	{
		if (temp->content[i] == '$')
		{
			//ft_putstr_fd(ft_getenv(temp->content[i], env), 1);
			temp= temp->next;
		}
		else
		{
			ft_putchar_fd(temp->content[i], 1);
			temp= temp->next;
		}
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(temp->content, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

void	ft_exec_echo(t_msvar *msv)
{
	t_dlist	*temp;
	
	temp = msv->block_list->next;
	if (temp->quote == '\'')
		ft_exec_echo_q(temp);
	else if (temp->quote == '\"')
		ft_exec_echo_dq(temp);
	else 
	{

	}
	ft_putstr_fd(msv->rline+5, 1);
	ft_putchar_fd('\n', 1);
}
