/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:01:46 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/07 16:15:42 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	c = (unsigned char)c;
	len = 0;
	while (s[len])
		len++;
	i = len;
	while (i > 0)
	{
		if ((unsigned char)s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	if ((unsigned char)s[0] == c)
		return ((char *)s);
	return (NULL);
}
