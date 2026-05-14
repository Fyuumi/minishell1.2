/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:37:55 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/07 16:38:52 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdlib.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}
/*
int	main(void)
{
		ft_putnbr_fd(42, 1);        // Print "42" to stdout
		ft_putchar_fd('\n', 1);     // Add newline
		ft_putnbr_fd(-123, 1);      // Print "-123" to stdout
		ft_putchar_fd('\n', 1);     // Add newline
		ft_putnbr_fd(0, 2);         // Print "0" to stderr
		ft_putchar_fd('\n', 2);     // Add newline
		return (0);
}
*/