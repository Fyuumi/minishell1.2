/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:19:47 by codespace         #+#    #+#             */
/*   Updated: 2026/05/14 18:21:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_apply_redirs(t_redir *). Opens < > >> and dup2s them.
For <<, it uses the fd already prepared in the redir node.*/