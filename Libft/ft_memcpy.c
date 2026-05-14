/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:01:05 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 19:18:15 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memcpy (memory copy) copie n octets d'une zone memoire source vers une
destination.
memcpy ne gere pas les zones qui se chevauchent, pour ca il faut memmove.
*/
#include "libft.h"

//#include <stdio.h>
//#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (NULL);
	s = src;
	d = dst;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	src[] = "Hello World";
	char	dst[20];

	ft_memcpy(dst, src, strlen(src) + 1); // +1 for null terminator
	printf("original: %s\n", src);
	printf("copy: %s\n", dst);
	return (0);
}
*/