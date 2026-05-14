/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:30:04 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/07 16:31:16 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/* #include <stdio.h>

Simple function: make character uppercase
void	to_upper(unsigned int i, char *c)
{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
}

int	main(void)
{
		char str[] = "hello";

		printf("Before: %s\n", str);
		ft_striteri(str, to_upper);
		printf("After: %s\n", str);
		return (0);
}
*/