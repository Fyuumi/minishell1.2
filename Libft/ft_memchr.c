/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:59 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 18:11:01 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memchr (memory character) recherche la premiere occurence d'un octet dans une
zone memoire, tout en ignorant '\0' contrairement a strchr.
*/
//#include <stdio.h>

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "Hello";
	char	*result;

	result = ft_memchr(str, 'l', 5);
	if (result)
		printf("Je l'ai !\n");
	else
		printf("J'ai pas.\n");
	return (0);
}
*/