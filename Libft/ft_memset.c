/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:01:18 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 19:53:48 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memset (memory set) remplit une zone memoire avec une valeur donnee, octet
par octet.
*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	buffer[10];

	// Fill buffer with 'A'
	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("Buffer: \"%s\"\n", buffer);
	// Fill with zeros
	ft_memset(buffer, 0, 10);
	printf("After zeroing: \"%s\"\n", buffer);
	return (0);
}
*/