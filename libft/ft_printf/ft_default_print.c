/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:19:58 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 05:20:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_default_print(t_printf *info)
{
	size_t	i;
	size_t	print_len;

	print_len = 0;
	i = ft_printlen_arg(info);
	if (info->id < 0)
		i++;
	while (i < info->width)
	{
		print_len += ft_write(" ", 1);
		i++;
	}
	print_len += ft_print_type(info);
	return (print_len);
}
