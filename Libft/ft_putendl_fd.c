/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:37:01 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/07 16:37:34 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}

/*
int	main(void)
{
	ft_putendl_fd("Hello World", 1);
	ft_putendl_fd("Test message", 1);
	return (0);
}
*/