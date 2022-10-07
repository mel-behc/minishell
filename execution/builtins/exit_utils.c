/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:24:30 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:24:32 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_error(t_args cmd)
{
	write (1, "exit\n", 5);
	printf ("Minishell: exit: %s: numeric argument required\n",
		cmd.arg[1]);
	exit (1);
}

void	ft_handlelong(t_args cmd)
{
	int	j;

	j = 0;
	while (cmd.arg[1][j])
	{
		if (!ft_strcmp(cmd.arg[1], "9223372036854775807"))
		{
			write (1, "exit\n", 5);
			g_mode.g_exit = 255;
			exit (255);
		}
		else
		{
			g_mode.g_exit = 255;
			ft_error(cmd);
		}
		j++;
	}
}

void	ft_negativenum(int j, t_args cmd)
{
	int	l;

	l = 0;
	if (cmd.arg[1][j] == '-')
	{
		l = j;
		while (cmd.arg[1][l])
		{
			l++;
			if (ft_isdigit(cmd.arg[1][l]))
			{
				write (1, "exit\n", 5);
				g_mode.g_exit = 256 + ft_atoi(cmd.arg[1]) % 256;
				exit (213);
			}
			else
				ft_error(cmd);
			l++;
		}
	}
}

void	ft_postifnum(int j, t_args cmd)
{
	int	len;
	int	l;

	l = j;
	len = ft_strlen(cmd.arg[1]);
	if (len < 19)
	{
		if (ft_isdigit(cmd.arg[1][l]))
		{
			write (1, "exit\n", 5);
			g_mode.g_exit = ft_atoi(&cmd.arg[1][l]) % 256;
			exit (ft_atoi(&cmd.arg[1][l]) % 256);
		}
		else
			ft_error(cmd);
	}
	else
		ft_handlelong(cmd);
}
