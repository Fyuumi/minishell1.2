/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:33:01 by codespace         #+#    #+#             */
/*   Updated: 2026/05/14 18:34:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_sig sets SIGINT and SIGQUIT handlers for the parent (interactive mode).
Uses rl_replace_line, rl_on_new_line, rl_redisplay.*/