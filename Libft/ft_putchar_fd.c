/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:31:36 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 20:06:11 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
putchar_fd ecrit un caractere sur un descripteur de fichier specifie.
fd : descripteur de fichier
(0 = stdin = standard input = clavier)
(1 = stdout = standard output = ecran)
(2 = stderr = standard error = sortie erreur (possible dans un autre fichier))
*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <unistd.h>

int	main(void)
{
	ft_putchar_fd('A', 1);
	return (0);
}
*/