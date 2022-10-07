/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:49:01 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:50:16 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_args	*skip_cmd(t_args *cmd)
{
	t_args	*tmp;

	tmp = cmd;
	while (tmp && tmp->type != COMMAND)
		tmp = tmp->next;
	return (tmp);
}

static int	out_checker(t_args *cmd)
{
	while (cmd)
	{
		if (cmd->type == OUT || cmd->type == APPEND)
			return (1);
		cmd = cmd->next;
	}
	return (0);
}

static t_args	*skip_file(t_args *cmd)
{
	t_args	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->type == APPEND || tmp->type == OUT)
			return (tmp);
		tmp = tmp->next;
	}
	return (cmd);
}

int	redirect_io(t_args *cmd, t_env *vars, int pipe)
{
	t_args	*tmp;
	int		stdout;
	int		stdin;
	int		fd[2];

	tmp = cmd;
	fd[0] = redirection_in(tmp, vars);
	if (out_checker(tmp) == 1)
		tmp = skip_file(tmp);
	fd[1] = redirection_out(tmp);
	tmp = skip_cmd(tmp);
	stdout = ft_duplicat_1(STDOUT_FILENO);
	stdin = ft_duplicat_1(STDIN_FILENO);
	if (pipe == 0)
		normal_io(tmp, vars, fd[0], fd[1]);
	else
		pipe_io(tmp, vars, fd[0], fd[1]);
	close_fd(0, fd[1]);
	dup_close_std(stdin, stdout);
	return (0);
}
