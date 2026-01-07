/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizetlen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:40:20 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 02:38:22 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_sizetlen_base(size_t n, const char *base)
{
	size_t	base_len;
	size_t	len;

	if (n == 0)
		return (1);
	base_len = ft_strlen(base);
	len = 0;
	while (n != 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
