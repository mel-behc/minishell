/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:28:40 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:28:42 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_getenv(char **envp)
{
	t_env	*save;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	save = NULL;
	while (envp[i])
	{
		key = ft_substr(envp[i], 0,
				ft_strlen(envp[i]) - ft_strlen(ft_strchr(envp[i], '=')));
		value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		ft_addbacknode(&save, ft_createcell(key, value));
		i++;
	}
	return (save);
}

char	*ft_getvalue(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return ("");
}

t_tk	*ft_expand(t_tk *list, t_env *ev)
{
	t_tk	*tmp;

	tmp = list;
	while (list && list->token != DOUTPUT)
	{
		if (list->token == VAR)
			list->input = ft_strdup(ft_getvalue(ev, list->input + 1));
		list = list->next;
	}
	return (tmp);
}

t_env	*ft_createcell(char *key, char	*value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(env));
	env->key = key;
	env->value = value;
	env->next = NULL;
	return (env);
}
