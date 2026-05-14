/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:41:50 by cdenaux           #+#    #+#             */
/*   Updated: 2026/04/23 15:42:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Helper to display the variable as "key=value\n"
Only displays if there's a value stored
write() instead of printf() to avoid leaks (possible buffer issue with pipes)*/

void ft_env_update(t_env *env, const char *key, const char *value)
{
    t_env_var *new_node;
    
    new_node = ft_new_node(key, value);
    ft_append_env_var(env, new_node);
    return ;
}
static void print_env_var(t_env_var *var)
{
    if (!var->value)
        return;
    write(STDOUT_FILENO, var->key, ft_strlen(var->key));
    write(STDOUT_FILENO, "=", 1);
    write(STDOUT_FILENO, var->value, ft_strlen(var->value));
    write(STDOUT_FILENO, "\n", 1);
}


/*Spans the linked list and displays each variable
Return 1 if env is not valid, otherwise 0
no options or arguments as asked in the subject*/


int ft_env(t_env *env)
{
    t_env_var   *current;

    if (!env || !env->vars)
        return (1);
    current = env->vars;
    while (current)
    {
        print_env_var(current);
        current = current->next;
    }
    return (0);
}
