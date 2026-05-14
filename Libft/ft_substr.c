/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:24:28 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/07 16:51:34 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue de la memoire et retourne une sous-chaine de 's'
s : la chaine source
start : l'index de debut de la sous-chaine
len : la longueur max de la sous-chaine
retourne : la sous-chaine, ou NULL si l'allocation echoue*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	actual_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	actual_len = s_len - start;
	if (actual_len > len)
		actual_len = len;
	substr = malloc(actual_len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, actual_len + 1);
	return (substr);
}
