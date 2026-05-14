/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:01:34 by cdenaux           #+#    #+#             */
/*   Updated: 2025/11/11 18:28:06 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int   main(void)
{
	char    *s = "Coucou";
	char    *sbis = "";

	printf("Longueur de %s -> %zu\n", s, ft_strlen(s));
	printf("Longueur de %s -> %zu", sbis, ft_strlen(sbis));
}*/