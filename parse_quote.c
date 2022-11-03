/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:25:16 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/04 00:26:44 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_quote_block(t_msvar *msv)
{
	msv->quote++;
	msv->i++;
	while (msv->rline[msv->i] != '\'' && msv->rline[msv->i] != '\0')
	{
		msv->w_len++;
		msv->i++;
	}
	if (msv->rline[msv->i] == '\'')
	{
		msv->quote++;
		msv->temp = ft_substr(msv->rline, msv->i - msv->w_len, msv->i);
		ft_dlstadd_back(&msv->block_list, ft_dlstnew(msv->temp, 0, 0, '\''));
		free(msv->temp);
		msv->w_count++;
	}
	if (msv->quote % 2 != 0)
				msv->parse_error = 2;
}

void	parse_dquote_block(t_msvar *msv)
{
	msv->dquote++;
	msv->i++;
	while (msv->rline[msv->i] != '"' && msv->rline[msv->i] != '\0')
	{
		msv->w_len++;
		msv->i++;
	}
	if (msv->rline[msv->i] == '"')
	{
		msv->dquote++;
		msv->temp = ft_substr(msv->rline, msv->i - msv->w_len, msv->i);
		ft_dlstadd_back(&msv->block_list, ft_dlstnew(msv->temp, 0, 0, '\"'));
		free(msv->temp);
	}
	if (msv->dquote % 2 != 0)
		msv->parse_error = 3;
}

void	parse_dollar_block(t_msvar *msv)
{
	(void)*msv;
	return ;
}

void	parse_nospl_block(t_msvar *msv)
{
	(void)*msv;
	return ;
}