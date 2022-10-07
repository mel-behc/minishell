/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:25:24 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:25:25 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expansion(t_env *envar, char *str)
{
	t_env	*tmp;
	int		length;

	tmp = envar;
	while (tmp)
	{
		length = ft_strlen(tmp->key);
		if (ft_strncmp(tmp->key, str, length) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
