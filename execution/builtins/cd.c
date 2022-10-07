/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:23:45 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/07 12:46:41 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	print_msg_error(void)
{
	ft_putstr_fd("cd: error retrieving current directory: ", 2);
	ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
	ft_putstr_fd("No such file or directory \n", 2);
}

static char	*error_path(char *var, t_env *vars)
{
	t_env	*tmp;
	int		length;

	tmp = vars;
	length = ft_strlen(var);
	while (tmp->next)
	{
		if (ft_strncmp(tmp->key, var, length) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_cd(t_args *line, t_env *envar)
{
	char	*path;
	char	*ret;

	path = NULL;
	if (!line->arg[1])
		home_direction(envar);
	else
	{
		if (chdir(line->arg[1]) == 0)
		{
			modify_oldpwd(envar);
			ret = getcwd(path, sizeof(path));
			modify_pwd(envar, ret, 1);
			if (!ret)
			{
				ret = error_path("OLDPWD", envar);
				ret = ft_strjoin_v2(ret, "/..");
				modify_pwd(envar, ret, 1);
				print_msg_error();
			}
		}
		else if (chdir(line->arg[1]) != 0)
		{
			perror("");
			g_mode.g_exit = 1;
		}
	}
}
