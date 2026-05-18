/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:21:25 by codespace         #+#    #+#             */
/*   Updated: 2026/05/17 16:18:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_is_builtin, ft_exec_builtin (used when builtin runs inside a child), and
ft_exec_single_builtin (save stdin/stdout, apply redirs manually, run builtin,
restore).*/

int ft_exec_builtin(t_cmd *cmd, t_env *env)
{
    if (!cmd || !cmd->argv || !cmd->argv[0])
        return (1);
    if (ft_strcmp(cmd->argv[0], "cd") == 0)
        return (ft_cd(cmd->argv, env));
    if (ft_strcmp(cmd->argv[0], "echo") == 0)
        return (ft_echo(cmd->argv));
    if (ft_strcmp(cmd->argv[0], "env") == 0)
        return (ft_env(env));
    if (ft_strcmp(cmd->argv[0], "exit") == 0)
        return (ft_exit(cmd->argv)); // *** ft_exit STILL IN PROGRESS ***
    if (ft_strcmp(cmd->argv[0], "export") == 0)
        return (ft_export(cmd->argv, env));
    if (ft_strcmp(cmd->argv[0], "pwd") == 0)
        return (ft_pwd());
    if (ft_strcmp(cmd->argv[0], "unset") == 0)
        return (ft_unset(cmd->argv, env));
    return (1);
}
