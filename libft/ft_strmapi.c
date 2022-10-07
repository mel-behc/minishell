/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:08:57 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:08:58 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	int		j;
	char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	temp = malloc ((j + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s[i])
	{
		temp[i] = f (i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
