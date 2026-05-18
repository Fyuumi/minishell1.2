/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:17:09 by codespace         #+#    #+#             */
/*   Updated: 2026/05/18 11:37:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*The fork/pipe loop (ft_execute). Adapted from Pipex code converted to walk a
t_cmd *cmds list. Also ft_run_execve (path + execve)*/

int ft_execute(t_cmd *cmds, t_env *env)
{
    int     pipe_fd[2];
    int     prev_pipe_read;
    pid_t   pid;
    int     status;
    t_cmd   *cur;

    prev_pipe_read = -1;
    status = 0;
    cur = cmds;

    //If only ONE command and it is a builtin -> NO FORK
    if (!cmds->next && ft_is_builtin(cmds->argv[0]))
    {
        ft_apply_redirs(cmds->redirs); // apply redirs IN PARENT
        return (ft_exec_single_builtin(cmds, env));
    } 
    
    while (cur)
    {
        if (cur->next && pipe(pipe_fd) == -1)
            return (perror("pipe"), 1);
        
        pid = fork();
        if (pid == 0) //child
        {
            if (prev_pipe_read != -1)
            {
                dup2(prev_pipe_read, STDIN_FILENO);
                close(prev_pipe_read);
            }
            if (cur->next)
            {
                dup2(pipe_fd[1], STDOUT_FILENO);
                close(pipe_fd[1]);
                close(pipe_fd[0]);
            }
            ft_apply_redirs(cur->redirs); // dup2 for > < >> <<
            if (ft_is_builtin(cur->argv[0]))
                ft_exit(ft_exec_builtin(cur, env));
            else
            {
                ft_run_execve(cur->argv, env); // our ft_get_cmd_path from Pipex
                ft_exit(1);
            }
        }
        // Parent
        if (prev_pipe_read != -1)
            close(prev_pipe_read);
        if (cur->next)
        {
            close(pipe_fd[1]);
            prev_pipe_read = pipe_fd[0];
        }
        cur = cur->next;
    }
    while (wait(&status) > 0) // wait for all children
        continue;
    return (WEXITSTATUS(status));
}
   