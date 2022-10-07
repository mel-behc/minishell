/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:27:42 by mel-behc          #+#    #+#             */
/*   Updated: 2022/09/27 10:27:43 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	my_exit(void)
{
	rl_on_new_line();
	rl_redisplay();
	printf("exit\n");
	exit (1);
}

t_args	*ft_corrector(t_args *parse)
{
	parse = ft_merge(parse);
	parse = ft_joiner(parse);
	return (parse);
}

static t_args	*lastparse(char *line, t_env *envar)
{
	t_tk		*list;
	t_tk		*tmp;
	t_args		*args;

	list = ft_lexer(line);
	list = ft_token_space(list);
	tmp = list;
	if (!ft_fullcheck(tmp))
		return (NULL);
	list = ft_expand(list, envar);
	args = ft_initialparsing(list);
	args = ft_corrector(args);
	return (args);
}

static void	ft_read_line(t_env *vars)
{
	char	*line;
	t_args	*cmd;

	while (1)
	{
		line = readline("minishell-1$ ");
		if (!line)
			my_exit();
		cmd = lastparse(line, vars);
		if (cmd && cmd->arg[0])
			g_mode.g_user_input = ft_strdup(cmd->arg[0]);
		ft_execution(cmd, &vars);
		// DONT FORGET 
		add_history (line);
		free (line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*envar;

	(void)av;
	g_mode.g_check = 0;
	g_mode.g_exit = 0;
	g_mode.g_sig = 0;
	g_mode.g_fork = 0;
	g_mode.g_user_input = NULL;
	ft_hide_c();
	if (ac != 1)
	{
		printf("\033[0;31m Invalid Number Arguments !\n");
		return (1);
	}
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, ft_handler);
	if (!*env)
	{
		env = var_list_backup();
		envar = create_var_list(env);
	}
	else
		envar = ft_getenv(env);
	modify_shlvl(envar);
	ft_read_line(envar);
	ft_show_c();
}
