/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:04:36 by takwak            #+#    #+#             */
/*   Updated: 2024/11/13 21:38:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//double free error
static void	free_all(char **strs, int i)
{
	while (--i >= 0)
	{
		free(strs[i]);
		strs[i] = NULL;
	}
	free(strs);
	strs = NULL;
}

static int	count_words(char const *s, char c)
{
	char	*tmp;
	int		cnt;

	tmp = (char *)s;
	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		tmp = ft_strchr(s, c);
		if (tmp == NULL)
			tmp = (char *)s + ft_strlen(s);
		s = tmp;
		cnt++;
	}
	return (cnt);
}

static	int	copy_words(char **splited, char const *s, char c)
{
	char	*tmp;
	int		cnt;

	tmp = (char *)s;
	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		tmp = ft_strchr(s, c);
		if (tmp == NULL)
			tmp = (char *)s + ft_strlen(s);
		splited[cnt] = (char *)malloc(sizeof(char) * (tmp - s + 1));
		if (splited[cnt] == NULL)
		{
			free_all(splited, cnt);
			return (0);
		}
		ft_strlcpy(splited[cnt++], s, tmp - s + 1);
		s = tmp;
	}
	splited[cnt] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		cnt;

	cnt = count_words(s, c);
	splited = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (splited == NULL)
		return (NULL);
	if (!copy_words(splited, s, c))
		return (NULL);
	return (splited);
}
