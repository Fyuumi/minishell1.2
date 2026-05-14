/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:00:41 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:17:18 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
bzero (byte zero) met a zero une zone de memoire. Elle fait partie des
fonctions BSD historiques mais est maintenant obsolete, remplacee par memset.
Principe : la fonction traite la memoire octet par octet :
- cast en unsigned char * : permet de manipuler la memoire octet par octet,
peut importe le type original.
- boucle simple : parcourt chaque octet et le met a zero.
- parametre void * : accepte n"importe quel type de pointeur

Differences avec memset :
bzero ne met qu'a zero, memset peut mettre n'importe quelle valeur.
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>
#include <string.h>
#include <strings.h>

void	print_buffer(char *buf, size_t size, const char *label)
{
	printf("%s: ", label);
	for (size_t i = 0; i < size; i++)
	{
		if (buf[i] == '\0')
			printf("\\0");
		else
			printf("%c", buf[i]);
	}
	printf("\n");
}

int	main(void)
{
	char	buf1[10] = "Hello";
	char	buf2[10] = "123456789";

	printf("Tests ft_bzero\n");
	printf("Avant : buf1 = \"Hello\"\n");
	ft_bzero(buf1, 5);
	printf("Apres ft_bzero(buf1, 5) : ");
	for (int i = 0; i < 10; i++)
		printf(buf1[i] == '\0' ? "\\0" : "%c", buf1[i]);
	printf("\n");
	printf("\nAvant : buf2 = \"123546789\"\n");
	ft_bzero(buf2 + 3, 3);
	print_buffer(buf2, 9, "Apres ft_bzero(buf2 +3, 3)");
	return (0);
}
 */