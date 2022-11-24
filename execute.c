/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:42:15 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/24 14:52:32 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_msvar *msv)
{
	if (msv->block_list->cmd_seq == 1)
		ft_exec_echo(msv);
	// if (msv->block_list->cmd_seq == 1)
	// 	ft_exec_export(msv);
	// else if (msv->block_list->content == 1)
	// 	ft_exec_pwd(msv);
	// if (msv->block_list->cmd_seq == 1)
	// 	ft_exec_env(msv);
}
// }