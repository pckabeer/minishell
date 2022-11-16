/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:44:56 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/11/16 23:29:42 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_exec_pwd(t_msvar *lst)
{
	t_env *temp;
	
	temp = lst->env_list;
	while(temp)
	{
		if(!(strncmp("PWD",temp->key,3)))
			ft_putstr_fd(temp->value,1);
		temp = temp->next;
	}
	ft_putchar_fd('\n',1);
	free(temp);
}

void ft_exec_env(t_msvar *lst)
{
	t_env *temp;
	
	temp = lst->env_list;
	while(temp)
	{
		ft_putstr_fd(temp->key,1);
		ft_putchar_fd('=',1);
		ft_putstr_fd(temp->value,1);
		ft_putchar_fd('\n',1);
		temp = temp->next;
	}
	free(temp);
}

void ft_exec_exit()
{
	exit(3);
}

void ft_exec_cd(t_msvar *lst)
{
	t_dlist *temp;
	printf("exec cd\n");
	temp = lst->block_list->content;
	ft_putstr_fd(temp->content,1);

	while(temp)
	{
		ft_putstr_fd(temp->content,1);
		ft_putchar_fd('\n',1);
	}
}
