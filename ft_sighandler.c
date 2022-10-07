/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sighandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:28:20 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:28:21 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_case_1(void)
{
	write (1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_mode.g_exit = 130;
}

static void	ft_case_2(void)
{
	write(1, "\n", 1);
	exit(1);
}

static void	ft_case_3(void)
{
	printf("Quit : 3\n");
	rl_replace_line("", 1);
	rl_on_new_line();
	g_mode.g_exit = 131;
}

static void	ft_case_4(void)
{
	rl_on_new_line();
	rl_redisplay();
}

void	ft_handler(int sig)
{
	int	i;

	i = 0;
	if (sig == SIGINT && g_mode.g_sig == 0 && g_mode.g_fork == 0)
		ft_case_1();
	else if (sig == SIGINT && g_mode.g_sig == 2)
		ft_case_2();
	else if (sig == SIGINT && g_mode.g_sig == 1)
		i++;
	else if (sig == SIGQUIT)
	{
		if (g_mode.g_fork == 1 && \
			ft_strcmp(g_mode.g_user_input, "./minishell") != 0)
			ft_case_3();
		else if (g_mode.g_fork == 0
			&& ft_strcmp(g_mode.g_user_input, "./minishell") != 0)
			ft_case_4();
		g_mode.g_exit = 131;
	}
	g_mode.g_fork = 0;
}
