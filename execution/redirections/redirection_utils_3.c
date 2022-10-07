/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:52:46 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:54:00 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	dup_close(int fd1, int fd2)
{
	if (fd1 != -1)
	{
		dup2(fd1, STDIN_FILENO);
		close(fd1);
	}
	if (fd2 != -1)
	{
		dup2(fd2, STDOUT_FILENO);
		close(fd2);
	}
}

int	close_fd(int fd1, int fd2)
{
	int	ret;

	ret = close(fd1);
	ret = close(fd2);
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	dup_close_std(int fd1, int fd2)
{
	ft_duplicat_2(fd1, STDIN_FILENO);
	ft_duplicat_2(fd2, STDOUT_FILENO);
	close_fd(fd1, fd2);
	return (0);
}
