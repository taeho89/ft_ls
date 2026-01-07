/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:43:11 by takwak            #+#    #+#             */
/*   Updated: 2024/10/27 23:43:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_custom(char *s1, char *s2, int s2_len)
{
	char	*new;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (*(s1 + s1_len) != '\0')
		s1_len++;
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			*(new + i) = *(s1 + i);
		else
			*(new + i) = *(s2 + i - s1_len);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*set_buffer(char *buf)
{
	int	i;

	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		i = 0;
		while (i <= BUFFER_SIZE)
			buf[i++] = '\0';
	}
	return (buf);
}
