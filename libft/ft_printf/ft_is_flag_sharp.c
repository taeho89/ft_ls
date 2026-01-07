/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag_sharp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:20:36 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 06:46:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_flag_sharp(t_printf *info)
{
	size_t	i;
	size_t	print_len;

	print_len = 0;
	i = ft_printlen_arg(info);
	if (ft_is_valid_type(info))
	{
		while (i + 2 < info->width)
		{
			print_len += ft_write(" ", 1);
		}
		if (info->ux != 0 && info->type == 'x')
			print_len += ft_write("0x", 2);
		if (info->ux != 0 && info->type == 'X')
			print_len += ft_write("0X", 2);
		print_len += ft_print_type(info);
		return (print_len);
	}
	return (ft_default_print(info));
}
