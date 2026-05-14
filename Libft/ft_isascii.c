/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:49 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:30:24 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isascii teste si un caractere appartient au jeu de caracteres ASCII standard.
Renvoie 1 si vrai ou 0 si faux.
*/
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Tests ft_isascii'\n");
	printf("ft_isascii('A') = %d\n", ft_isascii('A'));
	printf("ft_isascii('Z') = %d\n", ft_isascii('Z'));
	printf("ft_isascii('a') = %d\n", ft_isascii('a'));
	printf("ft_isascii('c') = %d\n", ft_isascii('c'));
	printf("ft_isascii('0') = %d\n", ft_isascii('0'));
	printf("ft_isascii('5') = %d\n", ft_isascii('5'));
	printf("ft_isascii('9') = %d\n", ft_isascii('9'));
	printf("ft_isascii(' ') = %d\n", ft_isascii(' '));
	printf("ft_isascii('@') = %d\n", ft_isascii('@'));
	printf("ft_isascii('-128') = %d\n", ft_isascii('-128'));
	printf("ft_isascii('-1') = %d\n", ft_isascii('-1'));
	return (0);
}
*/