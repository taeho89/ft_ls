/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:56:25 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 04:07:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(t_printf *info, size_t *total_len)
{
	if (info->type == '%')
	{
		write(1, "%", 1);
		*total_len += 1;
		return (1);
	}
	if (info->flag == '-')
		*total_len += ft_is_flag_minus(info);
	else if (info->flag == '+')
		*total_len += ft_is_flag_plus(info);
	else if (info->flag == ' ')
		*total_len += ft_is_flag_space(info);
	else if (info->flag == '#')
		*total_len += ft_is_flag_sharp(info);
	else if (info->flag == '0')
		*total_len += ft_is_flag_zero(info);
	else
		*total_len += ft_default_print(info);
	return (1);
}
