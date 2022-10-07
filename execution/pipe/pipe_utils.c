/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:47:04 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:47:05 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	pipe_counter(t_args *cmd)
{
	int	counter;

	counter = 0;
	while (cmd)
	{
		if (cmd->type == PIPE)
			counter++;
		cmd = cmd->next;
	}
	return (counter);
}

int	type_checker(t_args *tmp, t_env *vars)
{
	if (tmp->type != COMMAND)
		redirect_io(tmp, vars, 1);
	else
	{
		if (builtins_executor(tmp, &vars, 1) == 1)
			ft_execve(tmp, vars);
		else
			exit(0);
	}
	return (0);
}

void	ft_wait(t_args *cmd)
{
	int	counter;
	int	status;
	int	i;

	counter = pipe_counter(cmd);
	i = 0;
	g_mode.g_sig = 0;
	while (i < (counter + 1))
	{
		wait(&status);
		i++;
	}
	g_mode.g_fork = 0;
}

int	inherite_data(t_args *tmp, int fd1[2], int fd2[2])
{
	if (pipe_counter(tmp) > 0)
	{
		ft_close_fd(fd1, 2);
		copy_fds(fd1, fd2);
	}
	return (0);
}

void	copy_fds(int *fd1, int *fd2)
{
	fd1[0] = fd2[0];
	fd1[1] = fd2[1];
}
