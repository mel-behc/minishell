/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:28:09 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:05:57 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

static int	heredoc_loop(int *fd, t_env *envar, t_args *here)
{
	char	*heredoc;

	while (1)
	{
		heredoc = readline("> ");
		if (!heredoc)
		{
			free(heredoc);
			close ((*fd));
			return (1);
		}
		else if (!ft_strcmp(heredoc, *here->arg))
		{
			free(heredoc);
			close ((*fd));
			return (1);
		}
		else if (heredoc[0] == '$')
			heredoc = ft_getvalue(envar, &heredoc[1]);
		ft_putendl_fd(heredoc, (*fd));
	}
	return (0);
}

static int	end_of_function(int status)
{
	if (status == 0)
		return (open("/tmp/tmpfile", O_RDONLY, 0644));
	else
	{
		g_mode.g_sig = 0;
		return (-1);
	}
	return (0);
}

int	ft_document(t_args *here, t_env *envar)
{
	int	status;
	int	pid;
	int	fd;

	pid = fork();
	g_mode.g_sig = 1;
	fd = open("/tmp/tmpfile", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pid == 0)
	{
		g_mode.g_sig = 2;
		if (heredoc_loop(&fd, envar, here))
			exit(0);
		close (fd);
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	close(fd);
	g_mode.g_sig = 0;
	end_of_function(status);
	return (fd);
}
