/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:10:54 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:13:01 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tk	*ft_input(char *data, int token)
{
	t_tk	*list;

	list = NULL;
	list = malloc(sizeof(t_tk));
	if (!list)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(list));
	list->input = data;
	list->token = token;
	list->next = NULL;
	return (list);
}

t_tk	*ft_findlast(t_tk *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_addtolist(t_tk **list, t_tk *lst)
{
	if (*list)
		ft_findlast(*list)->next = lst;
	else
		*list = lst;
}

void	printlist(t_tk *list)
{
	if (list == NULL)
		return ;
	while (list)
	{
		printf("%d ---- [%s]\n", list->token, list->input);
		list = list->next;
	}
	puts("_______________\n");
}

t_args	*ft_args_node(char **ar, t_type type)
{
	t_args	*new;

	new = malloc(sizeof(t_args));
	if (!new)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(new));
	new->arg = ar;
	new->type = type;
	new->next = NULL;
	return (new);
}
