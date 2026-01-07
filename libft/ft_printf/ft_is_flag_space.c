/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:37:10 by takwak            #+#    #+#             */
/*   Updated: 2024/10/23 18:29:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_flag_space(t_printf *info)
{
	size_t	i;
	size_t	print_len;

	if (ft_is_valid_type(info))
	{
		print_len = 0;
		i = ft_printlen_arg(info);
		while (i + 1 < info->width)
		{
			print_len += ft_write(" ", 1);
			i++;
		}
		if (info->id >= 0)
			print_len += ft_write(" ", 1);
		print_len += ft_print_type(info);
		return (print_len);
	}
	return (ft_default_print(info));
}
