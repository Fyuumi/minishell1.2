/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:25:18 by codespace         #+#    #+#             */
/*   Updated: 2026/05/19 17:25:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_expand_cmds + ft_expand_str. Replaces $ VAR and $ ?, handles ' literal
and " semi-literal, then strips the quote characters.*/

void ft_expand_cmds(t_cmd *cmds, t_env *env, int last_status)
{
    char **str;
    char *line;
    char *new;
    int i;
    int flag;

    flag = 0;
    str = cmds->argv;
    line = str[0];
    new = malloc(ft_strlen(line) + 1);
    while(line[i])
    {
        
        if (line[i] == '"' && flag == 0)
        {
            flag = 1;
             i++;
        }
            i++;
        new[i] = line[i];
        i++;
    }
}