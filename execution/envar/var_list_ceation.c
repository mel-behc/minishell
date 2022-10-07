/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_list_ceation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:25:31 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:53:22 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*pwd_path(void)
{
	char	*path;
	char	*ret;

	path = NULL;
	ret = getcwd(path, sizeof(path));
	return (ret);
}

char	**var_list_backup(void)
{
	char	**tab;
	char	*path;
	int		length;

	path = pwd_path();
	tab = allocate_2d_tab(5);
	length = ft_strlen("OLDPWD");
	tab[0] = allocate_1d_tab(length);
	ft_strlcpy(tab[0], "OLDPWD", (length + 1));
	puts(tab[0]);
	length = ft_strlen("PWD=") + ft_strlen(path);
	tab[1] = allocate_1d_tab(length);
	ft_strlcpy(tab[1], "PWD=", (ft_strlen("PWD=") + 1));
	ft_strlcat(tab[1], path, (length + 1));
	length = ft_strlen("SHLVL=1");
	tab[2] = allocate_1d_tab(length);
	ft_strlcpy(tab[2], "SHLVL=1", (length + 1));
	length = ft_strlen("_=/usr/bin/env");
	tab[3] = allocate_1d_tab(length);
	ft_strlcpy(tab[3], "_=/usr/bin/env", (length + 1));
	tab[4] = NULL;
	return (tab);
}

t_env	*create_var_list(char **tab)
{
	t_env	*envar;
	int		i;

	i = -1;
	envar = NULL;
	while (tab[++i])
		add_node_at_end(&envar, var_name(tab[i]), var_value(tab[i]));
	return (envar);
}
