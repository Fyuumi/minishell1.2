/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:23:18 by codespace         #+#    #+#             */
/*   Updated: 2026/05/14 18:25:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_collect_heredocs(t_cmd *cmds). Walks all commands, finds every <<, creates
a pipe, reads line with readline("> ") until delimiter, writes to pipe,
stores pipe[0] in redir->fd.*/