/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_set_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 06:26:05 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 06:43:25 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prec_set_zero(char *itoa_n, size_t symbol, t_printf *info)
{
	char	*tmp;
	size_t	len;
	int		sign;

	len = ft_strlen(itoa_n);
	sign = 1;
	if (symbol != len)
		sign = -1;
	if (sign < 0)
		len--;
	tmp = (char *)ft_calloc(info->prec + 1, sizeof(char));
	ft_memset(tmp, '0', info->prec - len);
	if (sign < 0)
		ft_strlcat(tmp, itoa_n + 1, info->prec + 1);
	else
		ft_strlcat(tmp, itoa_n, info->prec + 1);
	return (tmp);
}
