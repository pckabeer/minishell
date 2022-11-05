/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:51:05 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/05 14:00:50 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	load_env(t_msvar *msv, char **env)
{
	int		i;
	char	*value;
	char	*temp;

	i = 0;
	while (env[i])
	{
		temp = ft_get_word(env[i], '=');
		value = ft_strdup(env[i] + ft_strlen(temp) + 1);
		ft_elstadd_back(&msv->env_list, ft_elstnew(temp, value));
		i++;
	}
}

/*
*	Accept the string to check in the environment variable and 
	returns the value if key exists
*/
char	*ft_getenv(char *str, t_env *env_list)
{
	while (env_list)
	{
		if (ft_strncmp(str, env_list->key,32767) == 0)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}