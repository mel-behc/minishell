/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:26:26 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:47:54 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	dp_close(int fd1, int fd2, int fd3)
{
	ft_duplicat_2(fd1, fd2);
	close(fd3);
}

static void	wait_dup_close(t_args *tmp, int fd)
{
	ft_wait(tmp);
	ft_duplicat_2(fd, STDIN_FILENO);
	close(fd);
}

static int	first_side(t_args *tmp, t_env *vars, int fd1[2])
{
	pid_t	pid;

	g_mode.g_fork = 1;
	if (tmp->type == HEREDOC && tmp->next->type == OUT)
		redirect_io(tmp, vars, 0);
	else if (tmp->type == HEREDOC)
		fd1[0] = ft_document(tmp, vars);
	else
	{
		pid = fork();
		if (pid == -1)
			return (1);
		else if (pid == 0)
		{
			ft_duplicat_2(fd1[1], STDOUT_FILENO);
			close(fd1[0]);
			type_checker(tmp, vars);
		}
	}
	return (0);
}

static int	other_side(t_args *tmp, t_env *vars, int fd1[2], int fd2[2])
{
	pid_t	pid;

	g_mode.g_fork = 1;
	if (tmp->type == HEREDOC && tmp->next && tmp->next->type == OUT)
		ft_document(tmp, vars);
	else if (tmp->type == HEREDOC)
		redirect_io(tmp, vars, 0);
	else
	{
		pid = fork();
		if (pid == -1)
			return (1);
		else if (pid == 0)
		{
			dp_close(fd1[0], STDIN_FILENO, fd1[1]);
			if (pipe_counter(tmp) > 0)
				dp_close(fd2[1], STDOUT_FILENO, fd2[0]);
			type_checker(tmp, vars);
		}
		inherite_data(tmp, fd1, fd2);
	}
	return (0);
}

int	ft_pipo(t_args *cmd, t_env *vars)
{
	t_args	*tmp;
	int		fd1[2];
	int		fd2[2];
	int		stdin;
	int		i;

	tmp = cmd;
	stdin = ft_duplicat_1(STDIN_FILENO);
	i = pipe_counter(cmd);
	while (tmp)
	{
		i = ft_pipe(tmp, fd1, fd2, i);
		if (tmp == cmd)
			first_side(tmp, vars, fd1);
		else if (tmp->type == PIPE)
		{
			tmp = tmp->next;
			other_side(tmp, vars, fd1, fd2);
		}
		tmp = tmp->next;
	}
	ft_close_fd(fd1, 2);
	wait_dup_close(cmd, stdin);
	return (EXIT_SUCCESS);
}
