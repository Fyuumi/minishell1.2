/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:50:24 by codespace         #+#    #+#             */
/*   Updated: 2026/05/21 10:40:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_exit(char **argv, int last_status)
{
	int i;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (!argv[1])
		exit(last_status);
	i = 0;
	if (argv[1][0] == '-' || argv[1][0] == '+')
		i++;
	while(argv[1][i])
	{
		if (!ft_isdigit((unsigned char)argv[1][i]))
		{
			ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(argv[1], STDERR_FILENO);
			ft_putendl_fd(": number arg required", STDERR_FILENO);
			exit(2);
		}
		i++;
	}
	if (argv[2])
	{
		ft_putendl_fd("Minishell: exit: too many args", STDERR_FILENO);
		return(1);
	}
	exit(ft_atoi(argv[1]));
}
