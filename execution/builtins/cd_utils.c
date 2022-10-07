/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:23:52 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:49:38 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	modify_pwd(t_env *envar, char *var, int checker)
{
	t_env	*tmp;

	tmp = envar;
	while (tmp->next)
	{
		if (ft_strncmp(tmp->key, "PWD", 3) == 0)
		{
			if (!checker)
				tmp->value = get_var_value(envar, var);
			else
				tmp->value = var;
			break ;
		}
		tmp = tmp->next;
	}
}

void	modify_oldpwd(t_env *envar)
{
	t_env	*tmp;

	tmp = envar;
	while (tmp->next)
	{
		if (ft_strncmp(tmp->key, "OLDPWD", 6) == 0)
		{
			tmp->value = get_var_value(envar, "PWD");
			break ;
		}
		tmp = tmp->next;
	}
}

char	*get_var_value(t_env *envar, char *var)
{
	t_env	*tmp;
	int		length;

	tmp = envar;
	length = ft_strlen(var);
	while (tmp->next)
	{
		if (ft_strncmp(tmp->key, var, length) == 0)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}

void	home_direction(t_env *vars)
{
	if (chdir(get_var_value(vars, "HOME")) == 0)
	{
		modify_oldpwd(vars);
		modify_pwd(vars, "HOME", 0);
	}
	else
		ft_putstr_fd("bash: cd: HOME not set \n", 2);
}
