/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:34:49 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/07 16:36:14 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
int	main(void)
{
		ft_putstr_fd("Hello", 1);        // Print to stdout
		ft_putstr_fd(" World", 1);       // Print to stdout
		ft_putstr_fd("\n", 1);           // Print newline
		ft_putstr_fd("Error", 2);        // Print to stderr
		ft_putstr_fd(NULL, 1);           // Test NULL (should do nothing)
		return (0);
}
*/