/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:39:45 by cdenaux           #+#    #+#             */
/*   Updated: 2026/05/18 17:52:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**cmd_input;
	t_env	*env;
	t_token	*token_list;
	t_cmd	*cmd_list;

	(void)argc;
	(void)argv;
	env = ft_init_env(envp);
	if (!env)
		return (1);
	while (1)
	{
		ft_pwd();
		ft_sig();
		input = readline("minishell$ ");
		if (!input)
			return (1);
		if (!input[0])
			continue ;
		if (*input)
			add_history(input);
		cmd_input = ft_split(input, ' ');
		token_list = ft_tokenizer(cmd_input, token_list);
		print_tokens(token_list);
		cmd_list = ft_parser(token_list);
		//print_cmds(cmd_list); //prints the list of arguments
		ft_exec_builtin(cmd_list, env);
		//ft_free_cmds(cmd_list); // responsible of core dumped with builtin echo
		//free(input);
		//ft_free_strtab(cmd_input);
		ft_free_tokens(&token_list);
		write(1, "\n", 1);
	}
}
