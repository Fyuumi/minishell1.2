/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:30:35 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:58:47 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
itoa (integer to ASCII) convertit un entier en chaine de caracteres.
C'est l'inverse d'atoi.
Approche :
1. int_len() : calcule la longueur necessaire.
2. pre_conv() : alloue la memoire.
3. fill_string() : remplit la chaine.
4. ft_itoa() : coordonne le tout.
	- utiliser long nbr = n; permet d'eviter l'overflow avec INT_MIN
*/
#include "libft.h"

//#include <stdlib.h>
//#include <stdio.h>

int	int_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*pre_conv(int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

static void	fill_string(char *result, long nbr, int len)
{
	int	i;

	i = len - 1;
	if (nbr == 0)
		result[0] = '0';
	else
	{
		while (nbr > 0)
		{
			result[i] = (nbr % 10) + '0';
			nbr /= 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	fill_string(result, nbr, len);
	return (result);
}

/*
int	main(void)
{
	char	*result;

	result = ft_itoa(123);
	printf("ft_itoa(123) = \"%s\"\n", result);
	free(result);
	result = ft_itoa(-456);
	printf("ft_itoa(-546) = \"%s\"\n", result);
	free(result);
	result = ft_itoa(0);
	printf("ft_itoa(0) = \"%s\"\n", result);
	free(result);
	return (0);
}
*/