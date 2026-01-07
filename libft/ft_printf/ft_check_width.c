/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:14:29 by takwak            #+#    #+#             */
/*   Updated: 2024/10/23 18:24:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_width(const char *s, t_printf *info)
{
	int	move;

	move = 0;
	while (ft_isdigit(*(s + move)))
	{
		info->width = info->width * 10 + (*(s + move) - '0');
		move++;
	}
	return (move);
}
