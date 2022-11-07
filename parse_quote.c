/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:25:16 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/07 21:16:11 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

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
		msv->temp = ft_substr(msv->rline, msv->i - msv->w_len, (msv->w_len));
		ft_dlstadd_back(&msv->block_list, ft_dlstnew(msv->temp, 0, 0, '\''));
		//free(msv->temp);
		msv->w_count++;
	}
	if (msv->quote % 2 != 0)
				msv->parse_error = 2;
}

void	parse_dquote_block(t_msvar *msv)
{
	msv->dquote++;
	msv->i++;
	msv->temp = ft_calloc(2, 1);
	// msv->outlen[0] = 1;
	while (msv->rline[msv->i] != '"' && msv->rline[msv->i] != '\0')
	{
		msv->w_len = ft_strlen(msv->output);
		if (msv->rline[msv->i] == '$')
		{
			// msv->output = ft_strjoin(msv->output,); 
			ft_strlcat(msv->output, parse_dollar_block(msv), 32767);
			printf("key: %s\n", msv->output);
		}
		else
		{
			ft_strlcat(msv->output, msv->temp, msv->w_len + 2);
			msv->temp[0] = msv->rline[msv->i];
			msv->w_len++;
			msv->i++;
		}
		printf("-- output: %s -- %c -- %s\n", msv->output, msv->rline[msv->i],msv->temp);
	}
	free(msv->temp);
	if (msv->rline[msv->i] == '"')
	{
		msv->dquote++;
		ft_dlstadd_back(&msv->block_list, ft_dlstnew(msv->output, 0, 0, '\"'));
	}
	if (msv->dquote % 2 != 0)
		msv->parse_error = 3;
}

/**
*  parse_dollar_block
* * parses the dollar block and fetches the value from the key parsed 
* * to the env_list 
*   @msv: struct with all the variables
*  return: value for the key
*/
char	*parse_dollar_block(t_msvar *msv)
{
	int		len;

	msv->i++;
	msv->temp = ft_get_word(msv->rline + msv->i, ' ');
	//printf("key: %s\n", msv->temp);
	len = ft_strlen(msv->temp);
	msv->i += len;
	msv->w_len += len;
	if (msv->temp[len - 1] == '"')
	{
		msv->temp[len - 1] = '\0';
		msv->temp = ft_getenv(msv->temp, msv->env_list);
		msv->temp[len - 1] = '"';
	}
	msv->temp = ft_getenv(msv->temp, msv->env_list);
	return (msv->temp);
}

/**
 * parse_nospl_block
 * * parses the block without any special characters
 *  @msv: struct with all the variables
 */
void	parse_nospl_block(t_msvar *msv)
{
	(void)*msv;
	return ;
}