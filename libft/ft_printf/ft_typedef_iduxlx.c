/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedef_iduxlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:36:49 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 02:38:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_i(va_list ap, t_printf *info)
{
	info->type = 'i';
	info->id = va_arg(ap, int);
}

void	ft_type_d(va_list ap, t_printf *info)
{
	info->type = 'd';
	info->id = va_arg(ap, int);
}

void	ft_type_u(va_list ap, t_printf *info)
{
	info->type = 'u';
	info->ux = va_arg(ap, unsigned int);
}

void	ft_type_x(va_list ap, t_printf *info)
{
	info->type = 'x';
	info->ux = va_arg(ap, unsigned int);
}

void	ft_type_largex(va_list ap, t_printf *info)
{
	info->type = 'X';
	info->ux = va_arg(ap, unsigned int);
}
