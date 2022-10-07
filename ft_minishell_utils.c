/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:28:33 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:02:08 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_delimiter(char c)
{
	if (!(c >= '0' && c <= '9') && !(c >= 'A' && c <= 'Z')
		&& !(c >= 'a' && c <= 'z') && c != '_' && c != '?')
		return (0);
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

char	**ft_table(char **tmp2, char *tmp1)
{
	char	**final_arr;
	int		i;

	i = 0;
	if (!tmp1)
		final_arr = NULL;
	if (!tmp2)
	{
		final_arr = malloc(sizeof(char *) * 2);
		ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(final_arr));
	}
	else
	{
		while (tmp2[i])
			i++;
		final_arr = malloc (sizeof(char *) * (i + 2));
		ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(final_arr));
		i = -1;
		while (tmp2[++i])
			final_arr[i] = ft_strdup(tmp2[i]);
	}
	final_arr[i++] = ft_strdup(tmp1);
	final_arr[i] = NULL;
	return (final_arr);
}
