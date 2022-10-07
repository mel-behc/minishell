/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:42 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 18:55:18 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_msg(char *var)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(var_name(var), 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	g_mode.g_exit = 1;
}

static char	**copy_list(t_env *envar)
{
	t_env	*tmp;
	char	**vars;
	int		space;
	int		i;

	space = var_counter(envar);
	vars = malloc((sizeof(char *) * space) + 1);
	if (!vars)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(vars));
	tmp = envar;
	i = -1;
	while (tmp)
	{
		vars[++i] = tmp->key;
		tmp = tmp->next;
	}
	return (vars);
}

static char	**sort_vars(t_env *envar)
{
	char	**tab;
	char	*swap;
	int		nvars;
	int		i;
	int		j;

	tab = copy_list(envar);
	nvars = var_counter(envar);
	i = -1;
	while (++i < (nvars - 1))
	{	
		j = 0;
		while (++j < nvars)
		{
			if (ft_strncmp(tab[j], tab[j - 1], 10) < 0)
			{
				swap = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = swap;
			}
		}
	}
	tab[i + 1] = NULL;
	return (tab);
}

static void	print_vars(char *name, char *value)
{
	if (name && value)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(name, 1);
		if (ft_strlen(value) > 1)
		{
			ft_putstr_fd("=", 1);
			ft_putchar_fd('"', 1);
			ft_putstr_fd(value, 1);
			ft_putchar_fd('"', 1);
		}
		ft_putchar_fd('\n', 1);
	}
}

void	sort_and_print(t_env **envar)
{
	char	**vars;
	char	*value;
	int		i;

	vars = sort_vars(*envar);
	i = -1;
	while (vars[++i])
	{
		value = expansion(*envar, vars[i]);
		print_vars(vars[i], value);
	}
}
