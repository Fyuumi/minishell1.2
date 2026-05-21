/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:17:09 by codespace         #+#    #+#             */
/*   Updated: 2026/05/20 15:59:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*The fork/pipe loop (ft_execute). Adapted from Pipex code converted to walk a
t_cmd *cmds list. Also ft_run_execve (path + execve)*/

void	ft_run_execve(char **argv, t_env *env)
{
	char	*cmd_path;

	if (!argv || !argv[0])
		exit(0);
	/*If user wrote a path (e.g. /bin/ls or ./a.out), do NOT search PATH*/
    cmd_path = get_cmd_path(argv[0], env->envp_array);
	if (ft_strchr(argv[0], '/'))
	{
		execve(argv[0], argv, env->envp_array);
		perror(argv[0]); // prints "No such file", "Permission denied", ...
		if (errno == ENOENT)
			exit(127);
		exit(126);
	}
	/*Otherwise search PATH*/
	if (!cmd_path)
	{
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(127);
	}
	execve(cmd_path, argv, env->envp_array);
	perror(argv[0]); // execve failed (rare: e.g. permission denied on resolved path)
	free(cmd_path);
	exit(126);
}
// void			ft_run_execve(char **str, t_env *env)
// {       pid_t     pid;
//         int		  status;

//         if (str[0])
//         {
//             pid = fork();
//             if (pid == 0)
//             {
//                 execve(str[0], str, ft_env_to_envp(env));
//                 ft_exit(1);
//             }
//             waitpid(pid, &status, 0);
//           }
//           else
//         {
//           write(STDOUT_FILENO, "command not found", 17);
//           write(STDOUT_FILENO, "\n", 1);
//         }
// }

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
    if (!cmds->next && ft_builtin_check(cmds->argv[0]) == 0)
    {
        ft_apply_redirs(cmds->redirs); // apply redirs IN PARENT
        return (ft_exec_single_builtin(cmds, env)); // still in progress
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
            //ft_apply_redirs(cur->redirs); // dup2 for > < >> <<
            if (ft_builtin_check(cur->argv[0]) == 0)
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
   