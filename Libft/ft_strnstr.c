/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:01:42 by cdenaux           #+#    #+#             */
/*   Updated: 2026/01/14 13:33:03 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && (i + j) < len
			&& needle[j] == haystack[i + j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *big;
// 	const char *small;

// 	big = "Hello World ouigjhkjibnh  iwuaroidfj njasgoiusfoigj ";
// 	small = "W";

// 	printf("Test fonction quand petit est dans grand : *** %s ***",
// 		ft_strnstr(big, small, 7));
// 	return (0);
// }