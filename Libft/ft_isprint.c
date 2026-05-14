/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:55 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:50:58 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isprint teste si un caractere est imprimable (visible a l'ecran), excluant
les caracteres de controle.
Renvoie 1 si vrai ou 0 si faux.
ASCII : 32 => espace ; 126 => ~
*/
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Tests ft_isprint'\n");
	printf("ft_isprint(' ') = %d\n", ft_isprint(32));
	printf("ft_isprint('0') = %d\n", ft_isprint(48));
	printf("ft_isprint('~') = %d\n", ft_isprint('~'));
	printf("ft_isprint('NUL') = %d\n", ft_isprint(0));
	printf("ft_isprint('TAB') = %d\n", ft_isprint(9));
	printf("ft_isprint('Etendu') = %d\n", ft_isprint(128));
	printf("ft_isprint('9') = %d\n", ft_isprint('9'));
	printf("ft_isprint('A') = %d\n", ft_isprint('A'));
	printf("ft_isprint('@') = %d\n", ft_isprint('@'));
	printf("ft_isprint('/') = %d\n", ft_isprint('/'));
	printf("ft_isprint('{') = %d\n", ft_isprint('{'));
	return (0);
}
*/