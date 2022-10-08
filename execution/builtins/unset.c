/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:25:07 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:53:04 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	error_msg(char *var)
{
	ft_putstr_fd("minishell: unset: ", 2);
	ft_putstr_fd(var_name(var), 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	g_mode.g_exit = 1;
}

static int	var_checker(char *var)
{
	int	i;

	i = -1;
	while (var[++i])
	{
		if (ft_isalpha(var[i]) == 0)
			return (0);
	}
	return (1);
}

static int	delete_from_beginning(char *name, t_env **envar)
{
	t_env	*tmp;
	int		length;

	tmp = *envar;
	length = ft_strlen(tmp->key);
	if (ft_strncmp(name, tmp->key, length) == 0)
	{
		tmp = (*envar)->next;
		free((*envar)->key);
		free((*envar)->value);
		free(*envar);
		(*envar) = tmp;
	}
	return (EXIT_SUCCESS);
}

static int	delete_from_middl(char *name, t_env *envar)
{
	t_env	*tmp1;
	t_env	*tmp2;
	int		length;

	tmp1 = envar;
	tmp2 = tmp1->next;
	while (tmp1->next)
	{
		length = ft_strlen(name);
		if (ft_strncmp(name, tmp2->key, length) == 0)
		{
			free(tmp1->next);
			tmp1->next = tmp2->next;
			return (1);
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return (EXIT_FAILURE);
}

void	ft_unset(t_args *line, t_env **envar)
{
	int		i;

	i = 0;
	if (var_counter(*envar) == 1)
	{
		if (ft_strcmp(line->arg[1], "_") != 0)
			delete_from_beginning(line->arg[1], envar);
		envar = NULL;
	}
	while (line->arg[++i])
	{	
		if (var_checker(line->arg[i]) == 1)
		{
			if (ft_strcmp(line->arg[i], "_") != 0)
			{
				delete_from_beginning(line->arg[i], envar);
				delete_from_middl(line->arg[i], *envar);
			}
		}
		else
			error_msg(line->arg[i]);
	}
}
