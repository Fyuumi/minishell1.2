/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:25:18 by codespace         #+#    #+#             */
/*   Updated: 2026/05/20 15:26:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_expand_cmds + ft_expand_str. Replaces $ VAR and $ ?, handles ' literal
and " semi-literal, then strips the quote characters.*/

// static void ft_expand_redirs(t_redir *redirs, t_expand_ctx *ctx)
// {
//     char *new_str;
    
//     while(redirs)
//     {
//         if (redirs->type != HEREDOC)
//         {
//             new_str = ft
//         }
//     }
// }

// void ft_expand_cmds(t_cmd *cmds, t_env *env, int last_status)
// {
//     t_expand_ctx    ctx;
//     t_cmd           *cur;
    
//     ctx.env = env;
//     ctx.last_status = last_status;
//     ctx.stdin_backup = -1;
//     ctx.stdout_backup = -1;
//     cur = cmds;
//     while(cur)
//     {
//         ft_expand_argv(cur, &ctx);
//         ft_expand_redirs(cur->redirs, &ctx);
//         cur = cur->next;
//     }
// }
