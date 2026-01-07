/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:23:04 by takwak            #+#    #+#             */
/*   Updated: 2024/10/22 21:24:01 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format_s, ...)
{
	va_list		ap;
	t_printf	*info;
	size_t		total_len;

	total_len = 0;
	va_start(ap, format_s);
	while (*format_s)
	{
		if (*format_s != '%')
			total_len += write(1, format_s++, 1);
		else
		{
			info = ft_init_struct(info);
			format_s++;
			format_s += ft_check_flag(format_s, info);
			format_s += ft_check_width(format_s, info);
			format_s += ft_check_prec(format_s, info);
			format_s += ft_check_type(format_s, ap, info);
			ft_print_arg(info, &total_len);
			free(info);
		}
	}
	va_end(ap);
	return (total_len);
}
