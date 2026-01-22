/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:14:29 by takwak            #+#    #+#             */
/*   Updated: 2026/01/22 15:38:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_width(const char *s, va_list ap, t_printf *info)
{
	int	move;

	move = 0;
	if (*s == '*') {
		info->width = va_arg(ap, size_t);
		move++;
		return (move);
	}
	while (ft_isdigit(*(s + move)))
	{
		info->width = info->width * 10 + (*(s + move) - '0');
		move++;
	}
	return (move);
}
