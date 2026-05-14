/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:01:02 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 20:13:32 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memcmp (memory compare) compare 2 zones memoire octet par octet,
independamment des caracteres nuls.
Difference avec strcmp qui s'arrete des '\0' et peut dire pareil par ex :
char	str1[] = "Hello\0World";
char	str2[] = "Hello\0Test";
strcmp(str1, str2); == 0 (identiques jusqu'au '\0')
memcmp(str1, str2, 12); != 0 (difference apres le '\0')
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "Hello";
	char	str3[] = "World";

	printf("Compare identical: %d\n", ft_memcmp(str1, str2, 5));     // 0
	printf("Compare different: %d\n", ft_memcmp(str1, str3, 5));     // negative
	printf("Compare first 2: %d\n", ft_memcmp("abc", "abd", 2));     // 0
	return (0);
}
*/