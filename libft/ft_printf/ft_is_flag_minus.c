/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 02:29:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_flag_minus(t_printf *info)
{
	size_t	print_len;

	print_len = 0;
	if (info->width <= (size_t)ft_printlen_arg(info))
		return (ft_print_type(info));
	else
	{
		print_len += ft_print_type(info);
		while (print_len < info->width)
		{
			print_len += ft_write(" ", 1);
		}
		return (print_len);
	}
}
