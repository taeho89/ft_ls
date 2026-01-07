/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:14:36 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 09:47:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_type(t_printf *info)
{
	size_t	len;

	if (info->type == 'c')
		len = ft_print_type_c(info->c);
	else if (info->type == 'p')
		len = ft_print_type_p(info->p);
	else if (info->type == 's')
		len = ft_print_type_s(info->s, info);
	else if (info->type == 'd' || info->type == 'i')
		len = ft_print_type_id(info->id, info);
	else if (info->type == 'u')
		len = ft_print_type_u(info->ux, info);
	else if (info->type == 'x')
		len = ft_print_type_x(info->ux, info);
	else if (info->type == 'X')
		len = ft_print_type_largex(info->ux, info);
	else
		return (ft_error("Invalid format type"));
	return (len);
}
