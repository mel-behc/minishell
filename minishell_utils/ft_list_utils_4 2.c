/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:11:05 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:12:35 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

t_args	*ft_last_arg(t_args *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_addbackarg(t_args **pars, t_args *nv)
{
	t_args	*tmp;

	tmp = (*pars);
	if ((*pars))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = nv;
	}
	else
		*pars = nv;
}

void	ft_printarg(t_args *args)
{
	int	i;

	i = 0;
	while (args)
	{
		i = 0;
		while (args->arg[i])
		{
			printf ("[%s]", args->arg[i]);
			i++;
		}
		printf(" == %d\n", args->type);
		args = args->next;
	}
}

t_env	*ft_last_node(t_env	*nv)
{
	while (nv)
	{
		if (nv->next == NULL)
			break ;
		nv = nv->next;
	}
	return (nv);
}

void	ft_addbacknode(t_env **env, t_env *nv)
{
	if (*env)
		ft_last_node(*env)->next = nv;
	else
		*env = nv;
}
