/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:50:12 by codespace         #+#    #+#             */
/*   Updated: 2026/05/18 11:15:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int ft_export(t_env *env, char *key)
// {   
//     if (!key)
//         return (1);
//     ft_append_env_var(env, ft_new_node(key, NULL));
//     return (0);
// } 

int ft_export(char **args, t_env *env)
{
    int i;
    int ret;

    if (!args[1])               // just "export" with no args
        return (ft_env(env));   // print env (bash behavior)
    
    ret = 0;
    i = 1;
    while (args[i])
    {
        if (!is_valid_identifier(args[i])) // e.g. "123" or "A-B"
        {
            ft_putstr_fd("export: not a valid identifier\n", STDERR_FILENO);
            ret = 1;
        }
        else
            ft_add_or_update_env(env, args[i]); // our helper *** TO BUILD **
        i++;
    }
    return (ret);
}
