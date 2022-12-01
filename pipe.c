/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:51:46 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/01 21:37:25 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

 void ft_exce_pipe(t_msvar *lst)
 {
	t_msvar *tmp;
    int pipe_fd[2];
	tmp = lst;
	
	if (pipe(pipe_fd) == -1) 
	{
        perror("pipe");
        exit(EXIT_FAILURE);
    }	

 }