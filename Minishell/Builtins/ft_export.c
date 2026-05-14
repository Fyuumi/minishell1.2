/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:50:12 by codespace         #+#    #+#             */
/*   Updated: 2026/04/23 15:24:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_export(t_env *env, char *key)
{   
    if (!key)
        return (1);
    ft_append_env_var(env, ft_new_node(key, NULL));
    return (0);
} 
