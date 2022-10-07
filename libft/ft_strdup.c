/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:49:07 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/07 12:49:54 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	temp = malloc((j + 1) * sizeof (char));
	if (!temp)
		return (0);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(temp));
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp [i] = '\0';
	return (temp);
}
