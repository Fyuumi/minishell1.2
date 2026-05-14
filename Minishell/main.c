/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:39:45 by cdenaux           #+#    #+#             */
/*   Updated: 2026/05/14 16:00:20 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Goal here:
minishell$ ls -l
minishell$ echo hello
minishell$ pwd
minishell$ nosuchcmd
minishell$ exit
*/

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
		token_list = ft_tokenizer(cmd_input);
		cmd_list = ft_parser(&token_list);
		ft_check_do_cmd(cmd_input, env, &cmd_list);
		// parse and execute the command
		free(input);
	}
}
