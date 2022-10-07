NAME = minishell

CFLAGS = -g -Wall -Werror -Wextra 
CC = cc
# -fsanitize=address
HEADER = minishell.h \

INCLUDE_READLINE = $(addprefix $(READLINE),/include)

LIB_READLINE = $(addprefix $(READLINE),/lib)

READLINE = $(shell brew --prefix readline)

NAME = minishell

SRC =	minishell.c\
		ft_collector.c\
		./minishell_utils/ft_list_utils_2.c\
		./minishell_utils/ft_list_utils_4.c\
		./parse/ft_preparse.c\
		./parse/ft_parsing.c\
		./parse/parsing_utils.c\
		./parse/ft_checksyntax.c\
		./token/ft_tokenization.c\
		./token/ft_token_utils.c\
		./token/ft_token_utils01.c\
		./token/ft_token_utils02.c\
		./token/ft_token_space.c\
		ft_environment.c\
		ft_sighandler.c\
		sig_utils.c\
		ft_minishell_utils.c\
		simple_command.c\
		execution.c\
		shlvl.c\
		utils_main.c\
		libft/ft_putstr_fd.c\
		libft/ft_strchr.c\
		libft/ft_bzero.c\
		libft/ft_strrchr.c\
		libft/ft_strdup.c\
		libft/ft_strlen.c\
		libft/ft_strncmp.c\
		libft/ft_substr.c\
		libft/ft_strtrim.c\
		libft/ft_isalpha.c\
		libft/ft_isalnum.c\
		libft/ft_split.c\
		libft/ft_strjoin.c\
		libft/ft_strlcpy.c\
		libft/ft_putchar_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_atoi.c\
		libft/ft_itoa.c\
		libft/ft_isdigit.c\
		execution/util_functions/utils_1.c \
		execution/util_functions/utils_2.c \
		execution/util_functions/node_creation.c \
		execution/envar/expansion_var.c \
		execution/envar/var_name_value.c \
		execution/envar/var_list_ceation.c \
		execution/builtins/cd_utils.c \
		execution/builtins/cd.c \
		execution/builtins/echo_cheker.c \
		execution/builtins/echo.c \
		execution/builtins/export00.c \
		execution/builtins/export01.c \
		execution/builtins/env.c \
		execution/builtins/pwd.c \
		execution/builtins/unset.c \
		execution/builtins/exit.c \
		execution/builtins/exit_utils.c \
		execution/execve/execve.c \
		execution/execve/path.c \
		execution/execve/tab_arg.c \
		execution/execve/tab_envar.c \
		execution/redirections/redirection.c\
		execution/redirections/redirection_utils.c\
		execution/redirections/redirection_utils_2.c\
		execution/redirections/redirection_utils_3.c\
		here_document.c\
		execution/pipe/pipe.c\
		execution/pipe/pipe_utils.c\
		execution/pipe/pipe_utils_2.c\


OBJS = $(SRC:.c=.o)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -I $(INCLUDE_READLINE) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE_READLINE)  -L $(LIB_READLINE) -o $(NAME) -lreadline
	clear

clean : 
	@rm -f $(OBJS)
	clear

fclean : clean
	@rm -f $(NAME)
	clear

re : fclean all