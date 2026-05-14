/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:17:09 by codespace         #+#    #+#             */
/*   Updated: 2026/05/14 18:19:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*The fork/pipe loop (ft_execute). Adapted from Pipex code converted to walk a
t_cmd *cmds list. Also ft_run_execve (path + execve)*/