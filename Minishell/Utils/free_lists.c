/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:27:27 by codespace         #+#    #+#             */
/*   Updated: 2026/05/18 17:50:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees all the lists token_list redirections_list cmd_list
void 	ft_free_tokens(t_token **tk)
{
    t_token *temp;
    t_token *copy;

    if (!tk || !*tk)
        return;
    copy = *tk;
    while(copy)
    {
        temp = copy->next;
        if (copy->str)
            free(copy->str);
        free(copy);
        copy = temp;
    }
    *tk = NULL;
}
    

void 	ft_free_redirs(t_redir *rd)
{
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

    while(cmd)
    {
        next = cmd->next;
        if (cmd->argv)
            ft_free_strtab(cmd->argv);
        if (cmd->redirs)
            ft_free_redirs(cmd->redirs);
        free(cmd);
        cmd = next;
    }
}
