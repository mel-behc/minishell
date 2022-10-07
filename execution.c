/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:27:24 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 19:35:45 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

static int	pipe_checker(t_args *cmd)
{
	t_args	*tmp;

	tmp = cmd;
	while (tmp->next)
	{
		if (tmp->type == PIPE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	redireciont_checker(t_args *cmd)
{
	t_args	*tmp;

	tmp = cmd;
	if ((tmp->type == IN || tmp->type == OUT) && (!pipe_checker(cmd)))
		return (1);
	else if ((tmp->type == APPEND || tmp->type == HEREDOC) \
			&& (!pipe_checker(cmd)))
		return (1);
	else if (pipe_checker(cmd) == 1)
		return (3);
	else if (tmp->type == COMMAND)
		return (4);
	return (0);
}

static int	execute_no_var(t_args *tmp, t_env **vars)
{
	if (tmp->type == HEREDOC)
		ft_document(tmp, *vars);
	else
		simple_command(tmp, vars);
	return (0);
}

int	ft_execution(t_args *cmd, t_env **vars)
{
	t_args	*tmp;

	tmp = cmd;
	if (cmd && !*vars)
		execute_no_var(tmp, vars);
	else if (cmd && *vars)
	{
		if (redireciont_checker(tmp) == 1)
		{
			if ((redirect_io(tmp, *vars, 0) == 1))
				return (EXIT_FAILURE);
		}
		else if (redireciont_checker(tmp) == 3)
		{
			if (ft_pipo(tmp, *vars) == 1)
				return (EXIT_FAILURE);
		}
		else if (redireciont_checker(tmp) == 4)
			simple_command(tmp, vars);
	}
	return (EXIT_SUCCESS);
}
