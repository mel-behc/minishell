/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:19:57 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:19:59 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_checkspace(int i, t_tk **list)
{
	ft_addtolist(list, ft_input(ft_strdup(" "), SP));
	return (i + 1);
}

int	ft_getword(char *line, int i)
{
	int	count;

	count = i;
	while ((line[i] && line[i] != ' ' && line[i] != '|'
			&& line[i] != '>' && line[i] != '<' && line[i] != '$'
			&& line[i] != '\'' && line[i] != '\"')
		|| (line[i] == ' ' && line[i - 1] == '\"' ))
	{
		count++;
		i++;
	}
	return (count);
}
