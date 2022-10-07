/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:11 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:50:48 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	quoute_checker(char *arg)
{
	int	length;

	length = ft_strlen(arg);
	if (arg[0] == 34 && arg[length - 1] == 34)
		return (1);
	else if (arg[0] == 39 && arg[length - 1] == 39)
		return (2);
	return (0);
}

char	*word_checker(char *arg)
{
	char	*word;
	int		checker;
	int		length;

	checker = quoute_checker(arg);
	if (checker == 1 || checker == 2)
	{
		length = ft_strlen(arg);
		word = (char *)malloc((sizeof(char) * (length - 2)) + 1);
		if (!word)
			return (NULL);
		ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(word));
		ft_strlcpy(word, &arg[1], (length - 1));
		return (word);
	}
	return (arg);
}
