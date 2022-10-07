/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:27:50 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:18:28 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	builtins_executor(t_args *line, t_env **vars, int pipe)
{
	if (ft_strncmp(line->arg[0], "echo", 5) == 0)
		ft_echo(line);
	else if (ft_strncmp(line->arg[0], "pwd", 4) == 0)
		ft_pwd(line, *vars);
	else if ((ft_strncmp(line->arg[0], "env", 4) == 0))
		ft_env(line, vars);
	else if (ft_strncmp(line->arg[0], "cd", 3) == 0)
		ft_cd(line, *vars);
	else if (ft_strncmp(line->arg[0], "unset", 6) == 0)
		ft_unset(line, vars);
	else if (ft_strncmp(line->arg[0], "export", 7) == 0)
		ft_export(line, vars);
	else if (ft_strncmp(line->arg[0], "exit", 5) == 0)
		ft_exit(g_mode.g_exit, pipe);
	else
		return (1);
	return (0);
}

int	function_executor(t_args *line, t_env **vars)
{
	pid_t	pid;
	int		status;

	g_mode.g_fork = 1;
	// ft_putstr_fd("IN THE FUNCTION EXECUTER \n", 2);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		ft_execve(line, *vars);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_mode.g_exit = status % 255;
	g_mode.g_fork = 0;
	return (0);
}

void	simple_command(t_args *line, t_env **vars)
{
	if (!(*vars))
	{
		if (builtins_executor(line, vars, 0) == 1)
			ft_putstr_fd("VAR environment variable not set.\n", 2);
	}
	else if (builtins_executor(line, vars, 0) == 1)
	{
		// ft_putstr_fd("AFTER BUILTINS CHECK \n", 2);
		function_executor(line, vars);
	}
}