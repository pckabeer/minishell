/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 04:05:03 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/09 04:32:40 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("An error while forking\n");
		return 1;	
	}
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input travel\n");
		scanf("%d",&x);
		write(fd[1] ,&x,1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0],&y,1);
		close(fd[0]);		
	}
	return 0;
}

