/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:57:15 by takwak            #+#    #+#             */
/*   Updated: 2024/10/05 19:04:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	last;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (ft_isset(s1[start], set) && s1[start])
		start++;
	last = ft_strlen(s1) - 1;
	while (ft_isset(s1[last], set) && last >= start)
		last--;
	if (last < start)
		trimmed = (char *)malloc(sizeof(char));
	else
		trimmed = (char *)malloc(sizeof(char) * (last - start + 2));
	if (trimmed == NULL)
		return (NULL);
	if (last < start)
		trimmed[0] = '\0';
	else
		ft_strlcpy(trimmed, s1 + start, last - start + 2);
	return (trimmed);
}
