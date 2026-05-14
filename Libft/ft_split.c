/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:50:57 by cdenaux           #+#    #+#             */
/*   Updated: 2025/07/07 16:55:31 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

static int	fill_result(char **result, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	end = 0;
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			result[i] = word_dup(s + start, end - start);
			if (!result[i])
				return (i);
			i++;
		}
	}
	result[i] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		failed_at;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	failed_at = fill_result(result, s, c);
	if (failed_at >= 0)
	{
		free_all(result, failed_at);
		return (NULL);
	}
	return (result);
}
/*
int	main(void)
{
	char	**words;

	words = ft_split("Testons,que,tout,fonctionne", ',');
	if (!words)
	{
		printf("Erreur : ft_split a echoue\n");
		return (1);
	}
	for (int i = 0; words[i]; i++)
		printf("%s\n", words[i]);
	for (int i = 0; words[i]; i++)
		free(words[i]);
	free(words);
	return (0);
}
*/