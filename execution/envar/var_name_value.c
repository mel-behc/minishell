/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_name_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:25:41 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:25:42 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	length_name(char *variable)
{
	int	i;

	i = -1;
	while (variable[++i])
	{
		if (variable[i] == '=')
			break ;
		else if (variable[i] == '+')
		{
			return (i + 2);
			break ;
		}
	}
	return (i + 1);
}

char	*var_name(char *variable)
{
	char	*name;
	int		length;

	length = length_name(variable);
	name = (char *)malloc((sizeof(char) * length) + 1);
	if (!name)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(name));
	ft_strlcpy(name, variable, length);
	return (name);
}

static int	length_value(char *variable)
{
	int	i;

	i = length_name(variable);
	while (variable[i])
		i++;
	return (i);
}

char	*var_value(char *variable)
{
	char	*value;
	int		length;
	int		start;

	length = length_value(variable);
	start = length_name(variable);
	value = (char *)malloc((sizeof(char) * length) + 1);
	if (!value)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(value));
	ft_strlcpy(value, &variable[start], length);
	return (value);
}
