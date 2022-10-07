/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:51:47 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:51:53 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	redirection_out(t_args *cmd)
{
	int	fd;

	fd = -1;
	if (cmd->type == OUT)
		fd = open_outfile(cmd);
	if (cmd->type == APPEND)
		fd = open_appfile(cmd);
	return (fd);
}

int	redirection_in(t_args *cmd, t_env *vars)
{
	int	fd;

	fd = -1;
	if (cmd->type == IN)
		fd = open_infile(cmd);
	if (cmd->type == HEREDOC)
		fd = open_herefile(cmd, vars);
	return (fd);
}

int	normal_io(t_args *cmd, t_env *vars, int fd1, int fd2)
{
	pid_t	pid;
	int		status;

	g_mode.g_fork = 1;
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		dup_close(fd1, fd2);
		if (builtins_executor(cmd, &vars) == 1)
			ft_execve(cmd, vars);
		else
			exit(0);
	}
	if (waitpid(pid, &status, 0) != -1)
	{
		if (WIFEXITED(status))
			g_mode.g_exit = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_mode.g_exit = WTERMSIG(status);
	}
	g_mode.g_fork = 0;
	return (0);
}

int	pipe_io(t_args *cmd, t_env *vars, int fd1, int fd2)
{
	dup_close(fd1, fd2);
	if (builtins_executor(cmd, &vars) == 1)
		ft_execve(cmd, vars);
	else
		exit(0);
	return (0);
}
