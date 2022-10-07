/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:09:47 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:09:48 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkbegin(char const *str, char const *c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_strchr(c, str[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	checkend(char const *str, char const *c)
{
	int	j;

	j = ft_strlen(str) - 1;
	while (str[j])
	{
		if (ft_strchr(c, str[j]) == 0)
			break ;
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		j;
	int		k;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	j = (checkend(s1, set) + 1);
	k = checkbegin(s1, set);
	if ((j - k) <= 0)
		return (ft_strdup (""));
	temp = malloc((j - k + 1) * sizeof (char));
	if (!temp)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(temp));
	while (k < j)
	{
		temp[i] = s1[k];
		i++;
		k++;
	}
	temp[i] = '\0';
	return (temp);
}
