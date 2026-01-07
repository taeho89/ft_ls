/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:52:40 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 05:27:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen_base(int n, const char *base)
{
	int		tmp;
	size_t	len;
	size_t	base_len;

	tmp = n;
	if (n == 0)
		return (1);
	base_len = ft_strlen(base);
	len = 0;
	while (tmp != 0)
	{
		tmp /= (int)base_len;
		len++;
	}
	return (len);
}
