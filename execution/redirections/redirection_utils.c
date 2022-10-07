/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:51:08 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:51:14 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	open_appfile(t_args *cmd)
{
	int		fd;

	fd = -1;
	while (cmd && cmd->type != COMMAND)
	{
		if (cmd->type == APPEND)
			fd = open(cmd->arg[0], O_RDWR | O_CREAT | O_APPEND, 0777);
		if (cmd->type == PIPE)
			break ;
		cmd = cmd->next;
	}
	return (fd);
}

int	open_outfile(t_args *cmd)
{
	int		fd;

	fd = -1;
	while (cmd && cmd->type != COMMAND)
	{
		if (cmd->type == OUT)
			fd = open(cmd->arg[0], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (cmd->type == PIPE)
			break ;
		cmd = cmd->next;
	}
	return (fd);
}

int	open_infile(t_args *cmd)
{
	int		fd;

	fd = -1;
	while (cmd && cmd->type != COMMAND)
	{
		if (cmd->type == IN)
			fd = open(cmd->arg[0], O_RDONLY);
		if (cmd->type == PIPE)
			break ;
		cmd = cmd->next;
	}
	return (fd);
}

int	open_herefile(t_args *cmd, t_env *vars)
{
	int		fd;

	fd = -1;
	while (cmd && cmd->type != COMMAND)
	{
		if (cmd->type == HEREDOC)
			fd = ft_document(cmd, vars);
		if (cmd->type == PIPE)
			break ;
		cmd = cmd->next;
	}
	return (fd);
}
