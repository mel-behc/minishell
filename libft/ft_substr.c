/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:10:00 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:10:01 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*temp;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen (&s[start]) < len)
	{
		temp = malloc (ft_strlen(&s[start] + 1) * sizeof(char));
		ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(temp));
	}
	else
		temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(temp));
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	while (len > i && s[i + start])
	{
		temp[i] = s[i + start];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
