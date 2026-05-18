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

const char	*token_type_to_str(t_type type)
{
	if (type == WORD)
		return ("WORD");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == REDIR_IN)
		return ("REDIR_IN");
	else if (type == REDIR_OUT)
		return ("REDIR_OUT");
	else if (type == HEREDOC)
		return ("HEREDOC");
	else if (type == APPEND)
		return ("APPEND");
	return ("UNKNOWN");
}

void	print_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		printf("Token %d:\n", i);
		printf("  type : %s\n", token_type_to_str(tokens->type));
		printf("  str  : %s\n", tokens->str);
		tokens = tokens->next;
		i++;
	}
}

void	print_redirs(t_redir *redir)
{
	int	i;

	i = 0;
	while (redir)
	{
		printf("    Redirection %d:\n", i);
		printf("      type : %s\n", token_type_to_str(redir->type));
		printf("      file : %s\n", redir->file);
		printf("      fd   : %d\n", redir->fd);
		redir = redir->next;
		i++;
	}
}

void	print_cmds(t_cmd *cmds)
{
	int	i;
	int	j;

	i = 0;
	while (cmds)
	{
		write(1,"=================================\n",20);
		printf("Command %d:\n", i);

		/* Print argv */
		if (cmds->argv)
		{
			j = 0;
			printf("  argv:\n");
			while (cmds->argv[j])
			{
				printf("    [%d] %s\n", j, cmds->argv[j]);
				j++;
			}
		}
		else
			printf("  argv: NULL\n");

		/* Print redirections */
		if (cmds->redirs)
		{
			printf("  redirs:\n");
			print_redirs(cmds->redirs);
		}
		else
			printf("  redirs: NONE\n");

		cmds = cmds->next;
		i++;
	}
	printf("=================================\n");
}

int ft_tokensize(t_token *token)
{
	t_token *temp;
	int count;

	count = 0;
	temp = token;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

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

t_cmd	*ft_create_parser_node(t_token *token_list, t_cmd *parse_list)
{
	t_cmd *parser_node;
	int i;
	char **temp;

	i = 0;
	parse_list = NULL;
	temp = malloc(sizeof(char*) * (ft_tokensize(token_list) + 1));
	if (!temp)
		return (NULL);
	while(token_list && token_list->type == WORD)
	{
		temp[i++] = token_list->str;
		token_list = token_list->next;
	}
	temp[i] = NULL;
	parser_node = malloc(sizeof(t_cmd));
	if (!parser_node)
		return (NULL);
	parser_node->argv = temp;
	parser_node->next = NULL;
	if(parse_list)
	{
		parse_list->next = parser_node;
		parse_list->next->next = NULL;
	}
	else
		parse_list = parser_node;
	return (parse_list);
}

t_cmd	*ft_parser(t_token *token_list)
{
	t_cmd	*parse_list;    // parsing system
	
	parse_list = NULL;
	while (token_list && token_list->str)
	{
		if (token_list->type == REDIR_IN || token_list->type == REDIR_OUT)
		{
			token_list = token_list->next; // skip the redirector
			parse_list->redirs = ft_create_redir_node(token_list);
				// copy tokens info to the redirector in parselist
		}
		else if (token_list->type == PIPE)
		{
			parse_list = parse_list->next; // arg++ because of Pipe
		}
		else if (token_list->type == WORD)
		{
			parse_list = ft_create_parser_node(token_list, parse_list);// adding to new Pipe
			parse_list->redirs = NULL;
			while(token_list && token_list->next && token_list->next->type == WORD)
				token_list = token_list->next;
		}
		token_list = token_list->next;
	}
	return (parse_list);
}
