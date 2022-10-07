/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:33:36 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 19:33:38 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("");
	return (pid);
}

int	ft_duplicat_1(int fd)
{
	int	std;

	std = dup(fd);
	if ((std) == -1)
	{
		perror("");
		return (EXIT_FAILURE);
	}
	return (std);
}

int	ft_duplicat_2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
	{
		perror("");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_close_fd(int *fd, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (close(fd[i]) == -1)
		{
			perror("");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
