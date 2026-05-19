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

