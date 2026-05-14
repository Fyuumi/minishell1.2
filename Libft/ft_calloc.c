/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:25:47 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/08 17:22:52 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
calloc (contiguous allocation) alloue de la memoire pour un tableau d'elements
et l'initialise a zero, contrairement a malloc qui laisse la memoire non
initialisee.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*int	main(void)
{
	int		*arr;
	char	*str;

	// test array 5 ints
	arr = (int *)ft_calloc(5, sizeof(int));
	if (!arr)
	{
		printf("memory failed!\n");
		return (1);
	}
	printf("Test 1 - Array of 5 integers:\n");
	printf("Values: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	// test array 10 chars
	str = (char *)ft_calloc(10, sizeof(char));
	if (!str)
	{
		printf("Memory allocation failed!\n");
		free(arr);
		return (1);
	}
	printf("\nTest 2 - Array of 10 chars:\n");
	printf("Contents: ");
	for (int i = 0; i < 10; i++)
	{
		if (str[i] == '\0')
			printf("\\0 ");
		else
			printf("%c ", str[i]);
	}
	printf("\n");
	// allocated memory
	printf("\nTest 3 - Writing to allocated memory:\n");
	arr[0] = 42;
	arr[1] = 100;
	str[0] = 'H';
	str[1] = 'i';
	printf("Modified int array: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Modified char array: \"%s\"\n", str);
	free(arr);
	free(str);
	return (0);
}*/