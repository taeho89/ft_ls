/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:29:31 by takwak            #+#    #+#             */
/*   Updated: 2026/01/22 15:40:01 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_prec(const char *s, va_list ap, t_printf *info)
{
	int	move;

	move = 0;
	if (*s == '.')
	{
		info->prec_flag = 1;
		move = 1;
		if (*(s + move) == '*') {
			info->prec = va_arg(ap, size_t);
			move++;
			return (move);
		}
		while (ft_isdigit(*(s + move)))
		{
			info->prec = info->prec * 10 + (*(s + move) - '0');
			move++;
		}
		return (move);
	}
	else
		return (0);
}
