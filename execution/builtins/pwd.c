/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:25:01 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:25:02 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	print_error_msg(void)
{
	ft_putstr_fd("pwd: too many arguments \n", 2);
	return (EXIT_FAILURE);
}

void	ft_pwd(t_args *line, t_env *envar)
{
	t_env	*tmp;

	tmp = envar;
	if (!line->arg[1])
	{
		while (tmp->next)
		{
			if (ft_strncmp(tmp->key, "PWD", 3) == 0)
			{
				ft_putstr_fd(tmp->value, 1);
				ft_putchar_fd('\n', 1);
			}
			tmp = tmp->next;
		}
	}
	else
		print_error_msg();
}
