/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:49:17 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 06:45:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_valid_type(t_printf *info)
{
	if (info->flag == '-')
		return (1);
	if (info->flag == '0')
		return (info->type == 'd' || info->type == 'i'
			|| info->type == 'u' || info->type == 'x'
			|| info->type == 'X');
	if (info->flag == '+' || info->flag == ' ')
		return (info->type == 'd' || info->type == 'i');
	if (info->flag == '#')
		return (info->type == 'x' || info->type == 'X');
	return (0);
}
