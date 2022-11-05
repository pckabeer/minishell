/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:51:05 by kpanikka          #+#    #+#             */
/*   Updated: 2022/11/05 11:29:25 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	load_env(t_msvar *msv, char **env)
{
	int		i;
	char	*value;
	t_env	*env_list;

	i = 0;
	while (env[i])
	{
		// msv->i = ft_strchr(env[i], '=') - env[i];
		// msv->temp = ft_substr(env[i], 0, msv->i);
		msv->temp = ft_get_word(env[i], '=');
		value = ft_strdup(env[i] + ft_strlen(msv->temp) + 1);
			printf("values : %s = %s\n", msv->temp, value);
		env_list = ft_elstnew(msv->temp, value);
			printf("%s = %s\n", env_list->key, env_list->value);
			if (i > 2)
			printf("from list : %s = %s\n", msv->env_list->key, msv->env_list->value);
			

		ft_elstadd_back(&msv->env_list,env_list );
			printf("from list : %s = %s\n", msv->env_list->key, msv->env_list->value);
		free(msv->temp);
		free(value);
		i++;
	}
	msv->i = 0;
}

/*
*	Accept the string to check in the environment variable and 
	returns the value if key exists
*/
char	*ft_getenv(char *str, t_env *env_list)
{
	while (env_list)
	{
		if (ft_strncmp(str, env_list->key, 32767) == 0)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}