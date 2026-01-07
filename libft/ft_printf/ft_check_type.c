/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:24:20 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 02:36:32 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(const char *s, va_list ap, t_printf *info)
{
	if (*s == 'c')
		ft_type_c(ap, info);
	else if (*s == 's')
		ft_type_s(ap, info);
	else if (*s == 'p')
		ft_type_p(ap, info);
	else if (*s == 'd')
		ft_type_d(ap, info);
	else if (*s == 'i')
		ft_type_i(ap, info);
	else if (*s == 'u')
		ft_type_u(ap, info);
	else if (*s == 'x')
		ft_type_x(ap, info);
	else if (*s == 'X')
		ft_type_largex(ap, info);
	else if (*s == '%')
		info->type = '%';
	else
		return (0);
	return (1);
}
