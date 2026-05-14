/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:52 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:48:46 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isdigit teste si un caractere est un chiffre decimal (0-9).
Renvoie 1 si vrai ou 0 si faux.
*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Tests ft_isdigit'\n");
	printf("ft_isdigit('A') = %d\n", ft_isdigit('A'));
	printf("ft_isdigit('Z') = %d\n", ft_isdigit('Z'));
	printf("ft_isdigit('a') = %d\n", ft_isdigit('a'));
	printf("ft_isdigit('c') = %d\n", ft_isdigit('c'));
	printf("ft_isdigit('0') = %d\n", ft_isdigit('0'));
	printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
	printf("ft_isdigit('9') = %d\n", ft_isdigit('9'));
	printf("ft_isdigit(' ') = %d\n", ft_isdigit(' '));
	printf("ft_isdigit('@') = %d\n", ft_isdigit('@'));
	printf("ft_isdigit('/') = %d\n", ft_isdigit('/'));
	printf("ft_isdigit('{') = %d\n", ft_isdigit('{'));
	return (0);
}
*/