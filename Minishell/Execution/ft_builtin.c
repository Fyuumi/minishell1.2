/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:21:25 by codespace         #+#    #+#             */
/*   Updated: 2026/05/18 17:06:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_builtin_check, ft_exec_builtin (used when builtin runs inside a child), and
ft_exec_single_builtin (save stdin/stdout, apply redirs manually, run builtin,
restore).*/


int	ft_exec_single_builtin(t_cmd *cmd, t_env *env) // save/restore stdio
{
    ft_exec_builtin(cmd, env);
    return (1);
}

int ft_builtin_check(char *arg) //checking if it is an builtin
{
    if (!arg)
        return (1);
    if (ft_strncmp(arg, "cd", 2) == 0)
        return (0);
    if (ft_strncmp(arg, "echo", 4) == 0)
        return (0);
    if (ft_strncmp(arg, "env", 3) == 0)
        return (0);
    if (ft_strncmp(arg, "exit", 4) == 0)
        return(0); 
    if (ft_strncmp(arg, "export", 6) == 0)
        return (0);
    if (ft_strncmp(arg, "pwd", 3) == 0)
        return (0);
    if (ft_strncmp(arg, "unset", 5) == 0)
        return (0);
    return (1);
}

int ft_exec_builtin(t_cmd *cmd, t_env *env)
{
    if (!cmd || !cmd->argv || !cmd->argv[0])
        return (1);
    if (ft_strncmp(cmd->argv[0], "cd", 2) == 0)
        return (ft_cd(cmd->argv, env));
    if (ft_strncmp(cmd->argv[0], "echo", 4) == 0)
        return (ft_echo(cmd->argv));
    if (ft_strncmp(cmd->argv[0], "env", 3) == 0)
        return (ft_env(env));
    if (ft_strncmp(cmd->argv[0], "exit", 4) == 0)
        ft_exit(1); // *** ft_exit STILL IN PROGRESS ***
    if (ft_strncmp(cmd->argv[0], "export", 6) == 0)
        return (ft_export(cmd->argv, env));
    if (ft_strncmp(cmd->argv[0], "pwd", 4) == 0)
        return (ft_pwd());
    if (ft_strncmp(cmd->argv[0], "unset", 5) == 0)
        return (ft_unset(cmd->argv, env));
    return (1);
}
