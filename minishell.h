/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:36 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/03 21:14:12 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "libft/libft.h"

# include <readline/readline.h>
# include <readline/history.h>

/*
* ! The struct s_dlist is a doubly linked list
	content is the data stored in the node
	next is the pointer to the next node
	prev is the pointer to the previous node
		len_quote is the length of the quote used for >> or << redirection 
	it will be 1 else for all it is 0
	cmd_seq is the command sequence number for the command 0 for no command 
		1 for first command 2 for second command and 
		so on till command 7 for exit
		after 7 the program will check if the command is there in the system  
		and then execute it or give an error
	is_opti is a flag to check if the command is a option or not
*/

typedef struct s_dlist
{
	char			*content;
	char            quote;
	int             len_quote;
	int             cmd_seq;
	int             is_option;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

/*
	cmd_num is the number to find which command 
	eg echo = 1 
		...


*/
typedef struct minishellvariables
{
	char	*rline;
	char	**env;
	int     i;
	char	*output;
	int		cmd_num;
	int		quote;
	int		dquote;
	int		num_pipe;
	int		parse_error;
	int		w_count;
	int		w_len;
	t_dlist	*block_list;
	char	*temp;
}t_msvar;

void	parse(t_msvar *msv);
void	parse_error(t_msvar *msv);
void	clean_exit(t_msvar *msv);
void	ft_exec(t_msvar *msv);
void	ft_exec_echo(t_msvar *msv);

t_dlist	*ft_dlstnew(char *data, int cmd_seq, int len_q, char q);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
int		ft_dlstsize(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst);
t_dlist	*ft_dlstlast(t_dlist *lst);

#endif