/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:59:40 by codespace         #+#    #+#             */
/*   Updated: 2026/05/15 17:59:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strtab(char **strtab)
{
	int	i;

	if (!strtab)
		return ;
	i = 0;
	while (strtab[i])
	{
		free(strtab[i]);
		i++;
	}
	free(strtab);
}
