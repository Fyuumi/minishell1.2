/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:44 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:26:11 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isalnum teste si un caractere est une lettre ou un chiffre.
Renvoie 1 si vrai ou 0 si faux.
*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Tests ft_isalnum'\n");
	printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));
	printf("ft_isalnum('Z') = %d\n", ft_isalnum('Z'));
	printf("ft_isalnum('a') = %d\n", ft_isalnum('a'));
	printf("ft_isalnum('c') = %d\n", ft_isalnum('c'));
	printf("ft_isalnum('0') = %d\n", ft_isalnum('0'));
	printf("ft_isalnum('5') = %d\n", ft_isalnum('5'));
	printf("ft_isalnum('9') = %d\n", ft_isalnum('9'));
	printf("ft_isalnum(' ') = %d\n", ft_isalnum(' '));
	printf("ft_isalnum('@') = %d\n", ft_isalnum('@'));
	printf("ft_isalnum('/') = %d\n", ft_isalnum('/'));
	printf("ft_isalnum('{') = %d\n", ft_isalnum('{'));
	return (0);
}
*/