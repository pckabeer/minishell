/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:42:15 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/16 00:21:21 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_cd(t_msvar *msv)
{
	(void) msv;
	return ;
}

void	ft_exec(t_msvar *msv)
{
	if (msv->block_list->cmd_seq == 1)
		ft_exec_echo(msv);
	else if (msv->block_list->cmd_seq == 2)
		ft_exec_cd(msv);
}