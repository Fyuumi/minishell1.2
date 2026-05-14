/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:48:07 by cdenaux           #+#    #+#             */
/*   Updated: 2026/01/15 12:05:36 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check(char *temp, char *buff)
{
	char	*result;

	if (!temp)
		return (ft_strdup(buff));
	result = ft_strjoin(temp, buff);
	free(temp);
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	ft_extract(char **ptr)
{
	char	*keep_temp;
	char	*newline_pos;

	newline_pos = ft_strchr(*ptr, '\n');
	if (!newline_pos)
	{
		free(*ptr);
		*ptr = NULL;
		return ;
	}
	if (*(newline_pos + 1) == '\0')
	{
		free(*ptr);
		*ptr = NULL;
		return ;
	}
	keep_temp = ft_strdup(newline_pos + 1);
	free(*ptr);
	*ptr = keep_temp;
}

char	*ft_cut_cpy_free(char **ptr_temp, ssize_t r_bytes)
{
	char	*line;
	char	*newline_pos;

	if (!*ptr_temp)
		return (NULL);
	if (r_bytes == 0 && **ptr_temp)
	{
		line = ft_strdup(*ptr_temp);
		free(*ptr_temp);
		*ptr_temp = NULL;
		return (line);
	}
	newline_pos = ft_strchr(*ptr_temp, '\n');
	if (newline_pos)
	{
		line = ft_substr(*ptr_temp, 0, newline_pos - *ptr_temp + 1);
		ft_extract(ptr_temp);
		return (line);
	}
	free(*ptr_temp);
	*ptr_temp = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buff;
	ssize_t		r_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (temp && ft_strchr(temp, '\n'))
			return (ft_cut_cpy_free(&temp, 1));
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		r_bytes = read(fd, buff, BUFFER_SIZE);
		if (r_bytes <= 0)
		{
			free(buff);
			return (ft_cut_cpy_free(&temp, r_bytes));
		}
		buff[r_bytes] = '\0';
		temp = ft_check(temp, buff);
		free(buff);
		if (!temp)
			return (NULL);
	}
}
