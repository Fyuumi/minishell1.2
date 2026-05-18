/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:50:24 by codespace         #+#    #+#             */
/*   Updated: 2026/05/18 10:51:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int signal)
{
	(void)signal;

	write(STDOUT_FILENO, "\n", 1);
	 ft_pwd();
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	// still in progress
}

void	ctrl_d(int signal)
{
	(void) signal;

	exit(1);
}

/*ft_sig sets SIGINT and SIGQUIT handlers for the parent (interactive mode).
Uses rl_replace_line, rl_on_new_line, rl_redisplay.*/

void	ft_sig(void)
{
	signal(SIGQUIT, SIG_IGN); // stops control c from closing
	signal(SIGINT, ctrl_d);   // control d closing
	signal(SIGINT, ctrl_c);   // gives control c a new thing to do	
}
