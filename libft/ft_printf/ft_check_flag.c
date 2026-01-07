/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:58:21 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 06:46:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isflag(char c)
{
	return (c == '-' || c == '+' || c == '0'
		|| c == ' ' || c == '#');
}

int	ft_check_flag(const char *s, t_printf *info)
{
	int	move;

	move = 0;
	while (ft_isflag(*(s + move)))
	{
		if (*s == '-')
			info->flag = '-';
		else if (*s == '+')
			info->flag = '+';
		else if (*s == '0')
			info->flag = '0';
		else if (*s == ' ')
			info->flag = ' ';
		else if (*s == '#')
			info->flag = '#';
		move++;
	}
	return (move);
}
