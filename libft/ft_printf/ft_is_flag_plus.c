/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:37:10 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 02:02:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_flag_plus(t_printf *info)
{
	size_t	i;
	size_t	print_len;

	print_len = 0;
	if (ft_is_valid_type(info))
	{
		i = ft_printlen_arg(info);
		while (i + 1 < info->width)
		{
			print_len += ft_write(" ", 1);
			i++;
		}
		if (info->id >= 0)
			print_len += ft_write("+", 1);
		print_len += ft_print_type(info);
		return (print_len);
	}
	return (ft_default_print(info));
}
