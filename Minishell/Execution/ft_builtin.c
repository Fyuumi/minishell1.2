/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:21:25 by codespace         #+#    #+#             */
/*   Updated: 2026/05/14 18:23:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*ft_is_builtin, ft_exec_builtin (used when builtin runs inside a child), and
ft_exec_single_builtin (save stdin/stdout, apply redirs manually, run builtin,
restore).*/