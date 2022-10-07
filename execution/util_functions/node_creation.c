/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:26:50 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 19:11:53 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_args	*create_cmd_node(char **str, enum e_type type)
{
	t_args	*node;

	node = (t_args *)malloc(sizeof(t_args));
	if (!node)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(node));
	node->arg = str;
	node->type = type;
	node->next = NULL;
	return (node);
}

t_env	*create_var_node(char *var, char *val)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	ft_addbackthegarbe(&g_mode.trash, ft_newgarbage(node));
	node->key = var;
	node->value = val;
	node->next = NULL;
	return (node);
}

void	add_node_at_end(t_env **head, char *var, char *val)
{
	t_env	*node;
	t_env	*tmp;

	tmp = *head;
	node = create_var_node(var, val);
	if (*head)
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		*head = node;
}
