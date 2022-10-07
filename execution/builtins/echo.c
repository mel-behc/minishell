/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:00 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 17:50:31 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	args_counter(char **args)
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	while (args[++i])
		counter++;
	return (counter);
}

static int	flag_checker(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		while (str[++i])
		{
			if (str[i] != 'n')
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

static int	flag_skip(char **args)
{
	int	flag;
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (args[++i])
	{
		flag = flag_checker(args[i]);
		if (flag == 1)
			ret++;
		else
			break ;
	}
	return (ret);
}

static void	print_args(t_args *line)
{
	t_args	*tmp;
	int		n_args;
	int		flag;
	int		i;

	tmp = line;
	n_args = args_counter(tmp->arg);
	flag = flag_skip(tmp->arg);
	i = flag;
	while (tmp->arg[++i])
	{
		tmp->arg[i] = word_checker(tmp->arg[i]);
		ft_putstr_fd(tmp->arg[i], 1);
		if (i != (n_args - 1))
			ft_putchar_fd(' ', 1);
	}
	if (flag == 0)
		ft_putchar_fd('\n', 1);
}

void	ft_echo(t_args *line)
{
	t_args	*tmp;

	tmp = line;
	print_args(tmp);
	g_mode.g_exit = 0;
}
