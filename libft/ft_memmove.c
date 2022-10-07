/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:48:34 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/07 12:48:38 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*des1;
	const char	*src1;
	size_t		i;

	src1 = (const char *)src;
	des1 = (char *) dst;
	i = 0;
	if (!des1 && !src1)
		return (NULL);
	else if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
		{
			des1[len] = src1[len];
		}
	}
	return (des1);
}
