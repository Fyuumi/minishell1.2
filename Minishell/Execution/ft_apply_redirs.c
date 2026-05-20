/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:19:47 by codespace         #+#    #+#             */
/*   Updated: 2026/05/19 16:55:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_apply_redirs(t_redir *). Opens < > >> and dup2s them.
For <<, it uses the fd already prepared in the redir node.*/

void ft_apply_redirs(t_redir *redirs)
{
    int fd;
    
    while (redirs)
    {
        if (redirs->type == REDIR_IN)
            fd = open(redirs->file, O_RDONLY);
        else if (redirs->type == REDIR_OUT)
            fd = open(redirs->file, O_WRONLY|O_CREAT|O_TRUNC, 0644);
        else if (redirs->type == APPEND)
            fd = open(redirs->file, O_WRONLY|O_CREAT|O_APPEND, 0644);
        else if (redirs->type == HEREDOC)
            fd = redirs->fd; // already prepared before fork
        
        if (fd == -1)
        {
            perror(redirs->file);
            ft_exit(1); // child dies, parent gets status 1
        }
        if (redirs->type == REDIR_IN || redirs->type == HEREDOC)
            dup2(fd, STDIN_FILENO);
        else
            dup2(fd, STDOUT_FILENO);
        close(fd);
        redirs = redirs->next;
    }
}
