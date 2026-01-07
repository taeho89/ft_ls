/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedef_cps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:41:54 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 02:38:32 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_c(va_list ap, t_printf *info)
{
	info->type = 'c';
	info->c = va_arg(ap, int);
}

void	ft_type_p(va_list ap, t_printf *info)
{
	info->type = 'p';
	info->p = va_arg(ap, size_t);
}

void	ft_type_s(va_list ap, t_printf *info)
{
	info->type = 's';
	info->s = va_arg(ap, char *);
}
