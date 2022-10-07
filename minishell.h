/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:29:09 by mel-behc          #+#    #+#             */
/*   Updated: 2022/10/04 19:17:33 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <termios.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/signal.h>
# include <sys/wait.h>
# include <sys/types.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef enum e_def{
	PIP,
	VAR,
	SQUOTE,
	DQUOTE,
	RINPUT,
	ROUTPUT,
	DINPUT,
	DOUTPUT,
	WORD,
	SP
}	t_def;

typedef enum e_type{
	COMMAND,
	PIPE,
	IN,
	OUT,
	APPEND,
	HEREDOC
}	t_type;

typedef struct s_env{
	char			*key;
	char			*value;
	struct s_env	*next;
}t_env;

typedef struct s_free{
	void			*ptr;
	struct s_free	*next;
}t_free;

typedef struct s_global{
	t_free	*trash;
	int		g_sig;
	int		g_exit;
	int		g_check;
	int		g_fork;
	char	*g_user_input;
}t_global;

t_global	g_mode;

typedef struct s_tk{
	char		*input;
	int			token;
	struct s_tk	*next;
}t_tk;

typedef struct s_args{
	char			**arg;
	t_type			type;
	struct s_args	*next;
}t_args;

// UTILS LIBFT
int		event(void);
char	*ft_substr(char const *s, int start, int len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_join2darray(char **tmp, char **temp);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy_v2(char *dst, const char *src);
char	*ft_strjoin_v2(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_isalpha(int c);
char	*ft_itoa(int n);
int		ft_isdigit(int c);

// LINKED LIST OF PARSING
t_tk	*ft_input(char *data, int token);
void	ft_freelist(t_tk *list);
t_tk	*ft_findlast(t_tk *lst);
void	ft_addtolist(t_tk **list, t_tk *lst);
void	printlist(t_tk *list);

// MINISHELL UTILS
char	**ft_table(char **tmp2, char *tmp1);
void	free_twodarray(char **str);
void	ft_extraspace(char *line);
int		ft_isspace(char c);
void	ft_free(char **tmp);

// LEXER
t_tk	*ft_token_space(t_tk *list);
t_tk	*ft_lexer(char *line);

// ENV AND ITS UTILS
t_env	*ft_createcell(char *key, char	*value);
void	ft_addbacknode(t_env **env, t_env *nv);
char	*ft_getvalue(t_env *env, char *key);
t_env	*ft_last_node(t_env	*nv);
t_env	*ft_getenv(char **envp);

// SIGNALS
void	sig_util(int status);
void	ft_handler(int sig);
void	ft_hide_c(void);
void	ft_show_c(void);

// LEXER UTILS
int		ft_checkdquotes(int i, char *line, t_tk **list);
int		ft_checksquotes(int i, char *line, t_tk **list);
int		ft_checkdollar(int i, char *line, t_tk **list);
int		ft_wildcard(char *line, int i, t_tk **list);
int		ft_checkrinput(int i, t_tk	**list);
int		ft_checkdoutput(int i, t_tk **list);
int		ft_checkroutput(int i, t_tk **list);
int		ft_checkdinput(int i, t_tk **list);
int		ft_checkspace(int i, t_tk **list);
int		ft_checkpip(int i, t_tk **list);
int		ft_getword(char *line, int i);
int		ft_delimiter(char c);

// EXPAND UTILS
t_tk	*ft_expand(t_tk *list, t_env *ev);

// PRASE AND PARSE UTILS
t_tk	*ft_initialparse(t_tk *list);
void	ft_addbackarg(t_args **pars, t_args *nv);

// SYNYAX ERROR
int		ft_syntaxredirection(t_tk *list);
int		ft_checksyntaxpip(t_tk *list);
int		ft_checkfirst(t_tk *list);
int		ft_fullcheck(t_tk *list);

// PRE PARSING
t_args	*ft_joiner(t_args *parse);
t_args	*ft_merge(t_args *parse);

// PARSING
void	ft_collectredirection(t_tk **list, t_args **redirection);
void	ft_collectheredoc(t_tk **list, t_args **herdoc);
void	ft_collectword(t_tk **list, t_args **word);
t_args	*ft_finalparsing(char *line, char **env);
void	ft_collectpip(t_tk **list, t_args **pip);
void	ft_collectinput(t_tk **list, t_args **redirection);

// MINISHELL UTILS
void	ft_addbacknode(t_env **env, t_env *nv);
t_env	*ft_createcell(char *key, char	*value);
t_args	*ft_args_node(char **ar, t_type type);
t_args	*ft_initialparsing(t_tk *list);
void	ft_printarg(t_args *args);
t_args	*ft_last_arg(t_args *lst);

// MAIN UTILS
void	my_exit(void);
t_args	*ft_corrector(t_args *parse);
// free
void	ft_freegarbe(t_free *list);
void	ft_addbackthegarbe(t_free **lst, t_free *nv);
t_free	*ft_lstgarbage(t_free *lst);
t_free	*ft_newgarbage(void *ptr);

				/****************************************************/
				/*					EXECUTION_PART					*/
				/***************************************************/

/********************************/
/*			UTILS				*/
/********************************/
char	*allocate_1d_tab(int length);
char	**allocate_2d_tab(int length);
int		var_counter(t_env *vars);
int		node_counter(t_args *node);
int		ft_duplicat_1(int fd);
int		ft_duplicat_2(int fd1, int fd2);
int		ft_close_fd(int *fd, int size);
void	modify_shlvl(t_env *vars);
pid_t	ft_fork(void);

/********************************/
/*			NODE_CREATION		*/
/********************************/
t_args	*create_cmd_node(char **str, enum e_type type);
t_env	*create_var_node(char *var, char *val);
char	*var_name(char *variable);
char	*var_value(char *variable);
void	add_node_at_end(t_env **head, char *var, char *val);

/********************************/
/*			ENVAR				*/
/********************************/
char	*expansion(t_env *envar, char *str);
t_env	*create_var_list(char **tab);
char	**var_list_backup(void);
/********************************/
/*			ECHO				*/
/********************************/
char	*word_checker(char *arg);
void	ft_echo(t_args *line);

/********************************/
/*			PWD					*/
/********************************/
void	ft_pwd(t_args *line, t_env *envar);

/********************************/
/*			ENV					*/
/********************************/
void	ft_env(t_args *line, t_env **envar);

/********************************/
/*			CD					*/
/********************************/
void	modify_pwd(t_env *envar, char *var, int checker);
void	modify_oldpwd(t_env *envar);
char	*get_var_value(t_env *envar, char *var);
void	home_direction(t_env *vars);
void	ft_cd(t_args *line, t_env *envar);

/********************************/
/*			UNSET				*/
/********************************/
void	ft_unset(t_args *line, t_env **envar);

/********************************/
/*			EXPORT				*/
/********************************/
void	print_msg(char *var);
void	sort_and_print(t_env **envar);
void	ft_export(t_args *line, t_env **envar);

/********************************/
/*			EXITX				*/
/********************************/
void	ft_negativenum(int j, t_args cmd);
void	ft_postifnum(int j, t_args cmd);
void	ft_handlelong(t_args cmd);
void	ft_error(t_args cmd);
int		ft_exit(t_args cmd);

/********************************/
/*			EXECVE				*/
/********************************/
char	**path_table(t_env *vars);
char	**arg_tab(t_args *cmd);
char	**tab_envar(t_env *envar);
int		ft_execve(t_args *line, t_env *envar);

/********************************/
/*			EXECUTE CMD			*/
/********************************/
int		builtins_executor(t_args *line, t_env **envar);
int		function_executor(t_args *line, t_env **vars);
void	simple_command(t_args *line, t_env **vars);
int		ft_execution(t_args *cmd, t_env **vars);

/********************************/
/*		IN_REDIRECTION			*/
/********************************/
int		dup_close_std(int fd1, int fd2);
int		close_fd(int fd1, int fd2);
void	dup_close(int fd1, int fd2);
int		open_herefile(t_args *cmd, t_env *vars);
int		open_infile(t_args *cmd);
int		open_appfile(t_args *cmd);
int		open_outfile(t_args *cmd);
int		ft_document(t_args *cmd, t_env *vars);
int		redirection_in(t_args *cmd, t_env *vars);
int		redirection_out(t_args *cmd);
int		normal_io(t_args *cmd, t_env *vars, int fd1, int fd2);
int		pipe_io(t_args *cmd, t_env *vars, int fd1, int fd2);
int		redirect_io(t_args *cmd, t_env *vars, int pipe);

/********************************/
/*			PIPE				*/
/********************************/
int		ft_pipe(t_args *cmd, int *fd1, int *fd2, int i);
void	copy_fds(int *fd1, int *fd2);
int		inherite_data(t_args *tmp, int fd1[2], int fd2[2]);
void	ft_wait(t_args *cmd);
int		type_checker(t_args *tmp, t_env *vars);
int		pipe_counter(t_args *cmd);
int		ft_pipo(t_args *cmd, t_env *vars);

#endif		
