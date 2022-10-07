/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:12:35 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 20:12:41 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hide_c(void)
{
	struct termios	att;

	tcgetattr(STDIN_FILENO, &att);
	att.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &att);
}

void	ft_show_c(void)
{
	struct termios	att;

	tcgetattr(STDIN_FILENO, &att);
	att.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &att);
}

void	sig_util(int status)
{
	if (WTERMSIG(status) == SIGINT)
	{
		puts("^C");
		g_mode.g_exit = WTERMSIG(status) + 128;
	}
}
