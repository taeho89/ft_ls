/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 05:29:31 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 06:45:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_prec(const char *s, t_printf *info)
{
	int	move;

	move = 0;
	if (*s == '.')
	{
		info->prec_flag = 1;
		move = 1;
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
