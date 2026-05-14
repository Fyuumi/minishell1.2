/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:58:32 by opaulman          #+#    #+#             */
/*   Updated: 2026/05/14 16:30:13 by opaulman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*ft_create_redir_node(t_token *token_node)
{
	t_redir	*redir_node;

	redir_node = malloc(sizeof(t_redir));
	if (!redir_node)
		return (0);
	ft_strlcpy(redir_node->file, token_node->str, ft_strlen(token_node->str));
	redir_node->next = NULL;
	redir_node->type = token_node->type;
	return (redir_node);
}

t_cmd	*ft_parser(t_token **token_list)
{
	t_cmd *parse_list;    // parsing system
	t_token *current;     // copy of token_list
	t_redir *redir_infos; // for storing the redirections in the parsing system
	current = *token_list;
	while (current && current->str)
	{
		if (current->type == REDIR_IN)
		{
			current = current->next; // skip the redirector
			if (current)
			{
				redir_infos = ft_create_redir_node(current);
				parse_list->redirs = redir_infos;
				// copy tokens info to the redirector in parselist
				current = current->next;
			}
			continue ;
		}
		if (current->type == PIPE)
		{
			parse_list = parse_list->next; // arg++ because of Pipe
			current = current->next;
		}
		ft_strjoin(*parse_list->args, current->str); // adding to new Pipe
		current = current->next;
	}
	return (parse_list);
}
