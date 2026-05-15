/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:50:58 by codespace         #+#    #+#             */
/*   Updated: 2026/05/15 19:54:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exec_builtin(t_cmd *cmd, t_env *env)
{
    if (!cmd || !cmd->argv || !cmd->argv[0])
        return (1);
    
    if (ft_strcmp)
}