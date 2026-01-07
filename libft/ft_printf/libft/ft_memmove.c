/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:57:22 by takwak            #+#    #+#             */
/*   Updated: 2024/10/17 20:12:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	size_t			i;

	if (dest == NULL && src == NULL)
		return ((void *)(0));
	i = 0;
	tmp_src = (unsigned char *)src;
	if ((size_t)src < (size_t)dest && (size_t)dest + n >= (size_t)src)
	{
		while (i < n)
		{
			*((unsigned char *)dest + n - 1 - i) = *(tmp_src + n - 1 - i);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*((unsigned char *)dest + i) = *(tmp_src + i);
			i++;
		}
	}
	return (dest);
}
