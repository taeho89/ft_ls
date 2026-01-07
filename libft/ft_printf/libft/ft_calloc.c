/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:45:33 by takwak            #+#    #+#             */
/*   Updated: 2024/10/06 17:53:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	i;

	if (size != 0 && nmemb > MAX_SIZE / size)
		return (NULL);
	tmp = malloc(size * nmemb);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
		*((unsigned char *)tmp + i++) = 0;
	return (tmp);
}
