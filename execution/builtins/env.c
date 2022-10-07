/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:20 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:51:12 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	print_vars(t_env *var)
{
	int	length;

	length = ft_strlen(var->key);
	if ((var->key[length - 1] == '=' && var->key[length] == '\0') || ft_strlen(var->value) > 0)
	{
		ft_putstr_fd(var->key, 1);
		if (var->key[length] != '\0')
			ft_putchar_fd('=', 1);
		ft_putstr_fd(var->value, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_env(t_args *line, t_env **envar)
{
	t_env	*tmp;

	tmp = *envar;
	if (!*envar)
		return ;
	if (!line->arg[1])
	{
		while (tmp && tmp->next)
		{
			if (tmp->value)
				print_vars(tmp);
			tmp = tmp->next;
		}
		print_vars(tmp);
	}
	else
	{	
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(line->arg[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_mode.g_exit = 127;
	}
}
