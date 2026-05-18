/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:27:27 by codespace         #+#    #+#             */
/*   Updated: 2026/05/14 18:28:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees all the lists token_list redirections_list cmd_list
void 	ft_free_tokens(t_token *tk)
{
    t_token *next;
    t_token *current;

    current = tk;
    while(current)
    {
        free(current->str);
        current = current->next;
    }
    free(tk);
}

void 	ft_free_redirs(t_redir *rd)
{
    t_redir *next;
    t_redir *current;

    current = rd;
    while(current)
    {
        free(current->file);
        current = current->next;
    }
    free(rd);
}

void	ft_free_cmds(t_cmd *cmd)
{
    t_cmd *next;
    t_cmd *current;

    current = cmd;
    while(current)
    {
        free_strtab(current->argv);
        current = current->next;
    }
    free(cmd);
}
