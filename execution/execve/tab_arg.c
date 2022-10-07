/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:26:08 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:55:14 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**arg_tab(t_args *cmd)
{
	char	**tab;
	int		length;
	int		i;

	length = node_counter(cmd);
	tab = allocate_2d_tab(length + 1);
	i = -1;
	while (cmd->arg[++i])
	{
		length = ft_strlen(cmd->arg[i]);
		tab[i] = allocate_1d_tab(length);
		ft_strlcpy(tab[i], cmd->arg[i], (length + 1));
	}
	tab[i] = NULL;
	return (tab);
}
