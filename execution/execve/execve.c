/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:25:51 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:46:25 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_path(char **cmd)
{
	if (cmd[0][0] == '.' && cmd[0][1] == '/')
		return (1);
	else if (cmd[0][0] == '/')
		return (1);
	return (0);
}

static char	*executable(t_args *line, char *bin)
{
	char	*exec;
	int		len_cmd;
	int		len_bin;
	int		total;

	len_bin = ft_strlen(bin);
	len_cmd = ft_strlen(line->arg[0]);
	total = len_bin + len_cmd + 2;
	exec = allocate_1d_tab(total + 1);
	ft_strlcat(exec, bin, total);
	ft_strlcat(exec, "/", total);
	ft_strlcat(exec, line->arg[0], total);
	return (exec);
}

static int	cmd_execution(t_args *line, char **path, char **envp)
{
	char	**args;
	char	*command;
	int		ret;
	int		i;

	i = -1;
	args = arg_tab(line);
	ret = -1;
	while (path[++i])
	{
		if (check_path(args) == 1)
			command = args[0];
		else
			command = executable(line, path[i]);
		if (access(command, X_OK) == 0)
			ret = execve(command, args, envp);
	}
	if (ret == -1)
	{
		ft_putstr_fd("minishell: command not found\n", 2);
		exit(127);
	}
	return (ret);
}

int	ft_execve(t_args *line, t_env *envar)
{
	char	**path;
	char	**envp;

	path = path_table(envar);
	envp = tab_envar(envar);
	if (cmd_execution(line, path, envp) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
