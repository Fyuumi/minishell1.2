/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:25:41 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:28:44 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isalpha teste si un caractere est une lettre.
Renvoie 1 si vrai ou 0 si faux.
*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Tests ft_isalpha'\n");
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
	printf("ft_isalpha('Z') = %d\n", ft_isalpha('Z'));
	printf("ft_isalpha('a') = %d\n", ft_isalpha('a'));
	printf("ft_isalpha('c') = %d\n", ft_isalpha('c'));
	printf("ft_isalpha('0') = %d\n", ft_isalpha('0'));
	printf("ft_isalpha('5') = %d\n", ft_isalpha('5'));
	printf("ft_isalpha('9') = %d\n", ft_isalpha('9'));
	printf("ft_isalpha(' ') = %d\n", ft_isalpha(' '));
	printf("ft_isalpha('@') = %d\n", ft_isalpha('@'));
	printf("ft_isalpha('/') = %d\n", ft_isalpha('/'));
	printf("ft_isalpha('{') = %d\n", ft_isalpha('{'));
	return (0);
}
*/