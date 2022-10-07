/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:26:01 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:54:50 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*get_path_value(t_env *vars)
{
	t_env	*tmp;

	tmp = vars;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "PATH", 5) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

static int	path_counter(char *path)
{
	int	counter;
	int	i;

	counter = 0;
	i = -1;
	while (path[++i])
	{
		if (path[i] == ':')
			counter++;
	}
	return (counter);
}

static int	length_of_path(char *path)
{
	int	length;

	length = -1;
	while (path[++length])
	{
		if (path[length] == ':')
			return (length);
		else if (path[length + 1] == '\0')
			return (length + 1);
	}
	return (0);
}

static void	fil_path_tab(t_env *vars, char **tab, int npath)
{
	char	*value;
	int		length;
	int		i;
	int		j;

	length = 0;
	i = 0;
	j = 0;
	value = get_path_value(vars);
	while (i < (npath + 1))
	{
		j = j + length;
		if (value[j] == ':')
			j = j + 1;
		length = length_of_path(&value[j]);
		tab[i] = allocate_1d_tab(length);
		ft_strlcpy(tab[i], &value[j], (length + 1));
		i++;
	}
}

char	**path_table(t_env *vars)
{
	char	**path_tab;
	int		space;

	space = path_counter(get_path_value(vars));
	path_tab = allocate_2d_tab(space);
	fil_path_tab(vars, path_tab, space);
	return (path_tab);
}
