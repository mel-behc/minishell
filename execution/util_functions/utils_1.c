/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:26:56 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 19:33:01 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lnd;
	size_t	lns;

	i = 0;
	j = 0;
	lnd = ft_strlen(dst);
	lns = ft_strlen(src);
	if (lnd > dstsize)
		return (dstsize + lns);
	while (dst[i])
		i++;
	while (i + 1 < dstsize && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (lnd + lns);
}

char	*allocate_1d_tab(int length)
{
	char	*ptr;

	ptr = (char *)malloc((sizeof(char) * length) + 1);
	if (!ptr)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(ptr));
	return (ptr);
}

char	**allocate_2d_tab(int length)
{
	char	**ptr;

	ptr = (char **)malloc((sizeof(char *) * length) + 1);
	if (!ptr)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(ptr));
	return (ptr);
}

int	var_counter(t_env *vars)
{
	int	counter;

	counter = 0;
	while (vars)
	{
		counter++;
		vars = vars->next;
	}
	return (counter);
}

int	node_counter(t_args *node)
{
	int	counter;

	counter = 0;
	while (node)
	{
		counter++;
		node = node->next;
	}
	return (counter);
}
