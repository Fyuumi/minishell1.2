/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:34:19 by codespace         #+#    #+#             */
/*   Updated: 2026/05/14 16:14:12 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// creates a list with the tokens
t_token	*ft_append_token(t_token *token_list, t_token *token_node)
{
	t_token	*current;

	if(token_list == NULL)
		return(token_node);
	current = token_list;
	while (current->next)
		current = current->next;
	current->next = token_node;
	return (token_list);
}
t_type	ft_typecheck(char *input)
{
	t_type	type;

	if (ft_strncmp(input, "|", 1) == 0)
		type = PIPE;
	else if (ft_strncmp(input, "<<", 2) == 0)
		type = HEREDOC;
	else if (ft_strncmp(input, ">>", 2) == 0)
		type = APPEND;
	else if (ft_strncmp(input, ">", 1) == 0)
		type = REDIR_IN;
	else if (ft_strncmp(input, "<", 1) == 0)
		type = REDIR_OUT;
	else
		type = WORD;
	return (type);
}
t_token	*ft_create_token_node(t_type token_type, char *input)
{
	t_token	*token_node;

	token_node = malloc(sizeof(t_token));
	if (!token_node)
		return (NULL);
	token_node->str = ft_strdup(input);
	token_node->next = NULL;
	token_node->type = token_type;
	return (token_node);
}

t_token	*ft_tokenizer(char **input, t_token *token_list)
{
	t_token	*token;
	t_type	type;
	int		i;

	i = 0;
	while (input[i])
	{
		type = ft_typecheck(input[i]);
		token = ft_create_token_node(type, input[i]);
		token_list = ft_append_token(token_list, token);
		i++;
	}
	return (token_list);
}
