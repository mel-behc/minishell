/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_envar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:26:15 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:55:57 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**tab_envar(t_env *envar)
{
	t_env	*tmp;
	char	**tab;
	int		length;
	// int		counetr;
	int		i;

	tmp = envar;
	length = var_counter(envar);
	tab = allocate_2d_tab(length);
	i = 0;
	while (tmp)
	{
		length = ft_strlen(tmp->key) + ft_strlen(tmp->value) + 2;
		tab[i] = allocate_1d_tab(length);
		ft_strlcat(tab[i], tmp->key, length);
		ft_strlcat(tab[i], "=", length);
		ft_strlcat(tab[i], tmp->value, length);
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
