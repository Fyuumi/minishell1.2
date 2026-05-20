/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:39:45 by cdenaux           #+#    #+#             */
/*   Updated: 2026/05/20 15:36:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void ft_shell_loop(t_env *env)
{
	char *input;
	t_token *token_list;
	t_cmd *cmd_list;
	//int status;

	//status = 0;
	token_list = NULL;
	while (1)
	{
		ft_sig(); // setup SIGINT / SIGQUIT
		input = readline("minishell$ ");
		if (!input)
			return;
		//if (!input[0])
		//continue ;
		if (*input)
			add_history(input);
		token_list = ft_tokenizer(ft_split(input, ' '), token_list);
		print_tokens(token_list);
		cmd_list = ft_parse_operator(token_list);
		print_cmds(cmd_list); //prints the list of arguments
		//ft_expand_cmds(cmd_list, env, status);
		ft_collect_heredocs(cmd_list); // fills heredoc fds
		ft_execute(cmd_list, env);
		//ft_free_cmds(cmd_list); // responsible of core dumped with builtin echo
		free(input);
		//ft_free_strtab(cmd_input);
		ft_free_tokens(&token_list);
		//write(1, "\n", 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	
	(void)argc;
	(void)argv;
	env = ft_init_env(envp);
	if (!env)
		return (1);
	ft_shell_loop(env);
	return (0);
}
