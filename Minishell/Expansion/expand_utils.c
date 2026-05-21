/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 13:18:38 by codespace         #+#    #+#             */
/*   Updated: 2026/05/20 13:48:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Appends src to dest, free dest, return new buffer*/
char    *ft_str_append(char *dest, const char *src)
{
    char *res;

    if (!dest)
        return (ft_strdup(src));
    res = ft_strjoin(dest, src);
    free(dest);
    return (res);
}

/*Looks up a key in env list, returns value or "" */
char    *ft_env_lookup(t_env *env, const char *key)
{
    t_env_var   *node;
    
    if (!env || !key)
        return ("");
    node = env->vars;

    while (node)
    {
        if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
        {
            if (node->value)
                return (node->value);
            return ("");
        }
        node = node->next;
    }
    return ("");
}
