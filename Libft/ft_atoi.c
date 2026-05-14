/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:31 by cdenaux           #+#    #+#             */
/*   Updated: 2025/11/11 18:38:30 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
atoi = ASCII to Integer : convertit une chaine de caracteres representant
un nombre en entier.
Principe : la conversion repose sur le fait que les caracteres '0' a '9'
ont des valeurs ASCII consecutives. Pour convertir un caractere chiffre en sa
valeur numerique, on soustrait la valeur ASCII de '0' :
- '0' a la valeur ASCII 48
- '1' a la valeur ASCII 49
- Donc '1' - '0' = 49 - 48 = 1
Le traitement se fait de gauche a droite, en multipliant le resultat actuel
par 10 avant d'ajouter un nouveau chiffre.
Points particuliers :
- s'arrete au premier caractere non numerique
- retourne 0 si aucun chiffre valide n'est trouve
- ignore les espaces en debut
*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("Tests ft_atoi\n");

	printf("ft_atoi(\"123\") = %d (attendu : 123)\n", ft_atoi("123"));
	printf("ft_atoi(\"-456\") = %d (attendu : -456)\n", ft_atoi("-456"));
	printf("ft_atoi(\"+789\") = %d (attendu : 789)\n", ft_atoi("+789"));

	printf("ft_atoi(\"     42\") = %d (attendu : 42)\n", ft_atoi("     42"));
	printf("ft_atoi(\"\\t-99\") = %d (attendu : -99)\n", ft_atoi("\t-99"));
	printf("ft_atoi(\"123abc\") = %d (attendu : 123)\n", ft_atoi("123abc"));

	printf("Comparaison avec atoi\n");

	const char *tests[] = {"123", "-456", "     42", "123abc", "0"};
	for (int i = 0; i < 5; i++)
	{
		int mes_resultats = ft_atoi(tests[i]);
		int std_resultats = atoi(tests[i]);
		printf("\"%s\": ft_atoi=%d, atoi=%d %s\n", tests[i], mes_resultats,
			std_resultats, (mes_resultats == std_resultats) ? "v" : "x");
	}
	return (0);
}*/