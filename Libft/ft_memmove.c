/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:01:15 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 19:48:48 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memmove est similaire a memcpy mais gere correctement les zones memoire qui
se chevauchent.
Pour l'implementation :
Si destination < source : copie de gauche a droite.
Si destination >= source : copie de droite a gauche.
*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hello World";

	// Test overlapping memory (move "World" to start)
	ft_memmove(str, str + 6, 5); // Copy "World" to beginning
	str[5] = '\0';               // Null terminate
	printf("Result: %s\n", str);
	return (0);
}
*/