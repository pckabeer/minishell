/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:42:15 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/16 03:44:57 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_msvar *msv)
{
	// if (msv->block_list->cmd_seq == 1)
	// {
	// 	ft_exec_echo(msv);
	// }
	// else if (msv->block_list->cmd_seq == 2)
	// {
	// 	ft_exec_cd(msv);
	// }
	// printf("cmd : %d\n",msv->block_list->cmd_seq);
	// if (msv->block_list->cmd_seq == 1)
	// {
	// 	ft_exec_pwd(msv);
	// }
	// if (msv->block_list->cmd_seq == 1)
	// {
	// 	ft_exec_env(msv);
	// }
	if (msv->block_list->cmd_seq == 1)
	{
		ft_exec_cd(msv);
	}
	
}