/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:30:46 by cdenaux           #+#    #+#             */
/*   Updated: 2026/05/18 17:51:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/*Structures*/
typedef struct s_env_var // One node = one variable
{
	char *key;   //"PATH"
	char *value; //"/usr/bin:/bin"
	struct s_env_var *next;
}					t_env_var;

typedef struct s_env
{
	t_env_var *vars;   // Head of the linked list
	char **envp_array; // Array used for execve(), can be NULL initially
}					t_env;

// Output of Lexer
// liked list with types for the strings
// example: echo hey | wc       echo WORD  hey WORD   | PIPE     wc WORD

typedef enum e_type
{
	WORD,      // command, arg, filename
	PIPE,      // |
	REDIR_IN,  // <
	REDIR_OUT, // >
	HEREDOC,   // <<
	APPEND,    // >>
}					t_type;

typedef struct s_token
{
	t_type			type;
	char			*str;
	struct s_token	*next;
}					t_token;

// parser output put words together, cut at pipes and attaches redirections
// Arg1 echo hey NULL Arg2 wc NULL
typedef struct s_redir
{
	t_type			type; // REDIR_IN, REDIR_OUT, HEREDOC, APPEND
	char			*file; // filename or heredoc delimiter
	int				fd; // set it to -1 by default in main
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd // Each t_cmd represents a segment between pipes
{
	char **argv;        // execve compatible: ["ls", "-la", NULL]
	t_redir *redirs;    // List of redirections for THIS cmd
	struct s_cmd *next; // Next command in the pipeline
}					t_cmd;

typedef struct s_expand_ctx
{
	t_env *env;      // To solve $VAR
	int last_status; // To solve $?
	int stdin_backup; // For redirection restoration
	int stdout_backup; // For redirection restoration
}					t_expand_ctx;

/*Global variable signal*/
extern int			g_signal_received;
// Only global allowed. Handles SIGINT and SIGQUIT.

/***** In Builtins/ *****/
//ft_cd:
int			ft_cd(char **args, t_env *env);
//ft_echo:
int			ft_echo(char **args);
//ft_env:
int			ft_env(t_env *env);
void		ft_env_update(t_env *env, const char *key,
						const char *value);
//ft_exit:
void		ctrl_c(int signal);
void		ctrl_d(int signal);
void		ft_sig(void);
void 		ft_exit(int n);
//ft_export:
int 		ft_is_valid_identifier(char *str);
int 		ft_export(char **args, t_env *env);
int			ft_unset(char **args, t_env *env);
//ft_pwd:
int			ft_pwd(void);


/***** In Execution/ *****/
//ft_apply_redirs:
void 		ft_apply_redirs(t_redir *redirs);
//ft_builtin:
int			ft_exec_single_builtin(t_cmd *cmd, t_env *env); // save/restore stdio
int			ft_builtin_check(char *cmd_name);
int			ft_exec_builtin(t_cmd *cmd, t_env *env);
//ft_execute:
int 		ft_execute(t_cmd *cmds, t_env *env);
//ft_heredoc:

/***** In Expansion/ *****/
//ft_expand:

/***** In Parsing/   *****/
// in ft_tokenizer
t_token		*ft_tokenizer(char **input, t_token *token_list);

// in ft_parser
void		print_tokens(t_token *tokens);
void		print_cmds(t_cmd *cmds);
t_cmd		*ft_parser(t_token *token_list);

/***** In Utils/ *****/
//cmd_utils_v2:
char		*ft_get_path(char **envp);
int			ft_is_exe(char *path);
char		*ft_get_cmd_path(char *cmd, char **envp);
char		*get_path(char **envp);
char		*get_cmd_path(char *cmd, char **envp);
void		ft_run_execve(char **argv, t_env *env);

//free_and_errors:
void		ft_free_strtab(char **strtab);
void 		ft_free_redirs(t_redir *rd);
void		ft_free_cmds(t_cmd *cmd);
//free_lists:
void 		ft_free_tokens(t_token **tk);

// in init_env
t_env_var	*ft_new_node(const char *key, const char *value);
char		**ft_env_to_envp(t_env *env);
t_env_var	*ft_new_env_var(char *envp);
void		ft_append_env_var(t_env *env, t_env_var *node);
t_env		*ft_init_env(char **envp);

// in ft_lstsizes.c
int 		ft_listsizes(void* content);

/*REDIRECTIONS => change name when file created*/

int ft_collect_heredocs(t_cmd *cmds); // pre-fork => fills redir -> fd


// /*REDIRECTIONS => change name when file created*/
// void ft_apply_redirs(t_redir *redirs);
// int ft_collect_heredocs(t_cmd *cmds); // pre-fork => fills redir -> fd

// /*EXPANDER => change name when file created*/
// void ft_expand_cmds(t_cmd *cmds, t_env *env, int last_status);
// char *ft_expand_str(char *str, t_env *env, int last_status);

// /*MAIN LOOP => change name when file created*/
// void ft_shell_loop(t_env *env);


#endif
