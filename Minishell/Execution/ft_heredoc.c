/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:23:18 by codespace         #+#    #+#             */
/*   Updated: 2026/05/20 11:42:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_collect_heredocs(t_cmd *cmds). Walks all commands, finds every <<, creates
a pipe, reads line with readline("> ") until delimiter, writes to pipe,
stores pipe[0] in redir->fd.*/

int ft_handle_heredoc(t_redir *redir)
{
    int pipefd[2];
    char *str;

    if(pipe(pipefd) == -1)
        return(1);
    while(1)
    {
        str = readline("> ");
        if(!str)
            break;
            if (ft_strncmp(str, redir->file, ft_strlen(str)))
            {
                free(str);
                break;
            }
        write(pipefd[1], str, ft_strlen(str));
        write(pipefd[1], "\n", 1);
        free(str);
    }
    close(pipefd[1]);
    redir->fd = pipefd[0];
    return (0);
}

int ft_collect_heredocs(t_cmd *cmd_list)
{
    t_cmd   *cmd;
    t_redir *redir;

    cmd = cmd_list;
    while(cmd)
    {
        redir = cmd->redirs;
        while(redir)
        {
            if(redir->type == HEREDOC)
            {
                if (ft_handle_heredoc(redir))
                    return (1);
            }
            redir = redir->next;
        }
        cmd = cmd->next;
    }
    return (0);
}
