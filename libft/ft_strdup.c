

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
