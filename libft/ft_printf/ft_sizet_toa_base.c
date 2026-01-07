/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizet_toa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:48:54 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 03:43:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sizet_toa_base(size_t n, const char *base)
{
	size_t	base_len;
	size_t	tmp_len;
	char	*tmp;

	if (n == 0)
	{
		tmp = (char *)malloc(sizeof(char) * (2));
		tmp[0] = '0';
		tmp[1] = '\0';
		return (tmp);
	}
	base_len = ft_strlen(base);
	tmp_len = ft_sizetlen_base(n, base);
	tmp = (char *)malloc(sizeof(char) * (tmp_len + 1));
	tmp[tmp_len--] = '\0';
	while (n != 0)
	{
		tmp[tmp_len--] = base[n % base_len];
		n /= base_len;
	}
	return (tmp);
}
