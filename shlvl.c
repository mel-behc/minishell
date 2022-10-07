/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:17:37 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:17:52 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	modify_shlvl(t_env *vars)
{
	t_env	*tmp;
	int		shlvl;

	tmp = vars;
	while (tmp)
	{
		if (ft_strncmp("SHLVL", tmp->key, 6) == 0)
			shlvl = ft_atoi(tmp->value) + 1;
		tmp = tmp->next;
	}
	tmp = vars;
	while (tmp)
	{
		if (ft_strncmp("SHLVL", tmp->key, 6) == 0)
			tmp->value = ft_itoa(shlvl);
		tmp = tmp->next;
	}
}
