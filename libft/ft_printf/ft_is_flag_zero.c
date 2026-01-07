/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:17:43 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 06:14:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_flag_zero_negative(t_printf *info, size_t printlen)
{
	char	*tmp;
	size_t	i;
	size_t	print_len;

	print_len = 0;
	i = printlen;
	tmp = ft_itoa(info->id);
	print_len += ft_write("-", 1);
	while (i + 1 < info->width)
	{
		print_len += ft_write("0", 1);
		i++;
	}
	print_len += ft_write(tmp + 1, ft_strlen(tmp + 1));
	free(tmp);
	return (print_len);
}

size_t	ft_is_flag_zero(t_printf *info)
{
	size_t	i;
	size_t	print_len;

	print_len = 0;
	i = ft_printlen_arg(info);
	if (ft_is_valid_type(info))
	{
		if (info->prec_flag && (info->prec <= i || info->prec == 0))
			return (ft_default_print(info));
		if (info->id < 0)
			return (ft_flag_zero_negative(info, i));
		while (i < info->width)
		{
			print_len += ft_write("0", 1);
			i++;
		}
		print_len += ft_print_type(info);
		return (print_len);
	}
	else
		return (ft_default_print(info));
}
