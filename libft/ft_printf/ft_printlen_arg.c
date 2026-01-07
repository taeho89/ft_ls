/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlen_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:48:47 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 07:11:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_allzero(t_printf *info)
{
	if (info->prec_flag && info->prec == 0)
	{
		if (info->type == 'd' || info->type == 'i')
			return (info->id == 0);
		if (info->type == 'u' || info->type == 'x' || info->type == 'X')
			return (info->ux == 0);
	}
	return (0);
}

static int	ft_printlen_type_p(t_printf *info)
{
	if (info->p == 0)
		return (5);
	return (ft_sizetlen_base(info->p, "0123456789abcdef") + 2);
}

static int	ft_printlen_type_s(t_printf *info)
{
	size_t	len;

	len = ft_strlen(info->s);
	if (info->s == NULL)
	{
		len = 6;
		if (info->prec_flag && info->prec < 6)
			return (0);
		return (len);
	}
	else if (info->prec_flag && info->prec <= len)
		return (info->prec);
	return (len);
}

int	ft_printlen_arg(t_printf *info)
{
	info->prt_len = 0;
	if (ft_is_allzero(info))
		return (0);
	if (info->type == 'c')
		info->prt_len = 1;
	else if (info->type == 'p')
		info->prt_len = ft_printlen_type_p(info);
	else if (info->type == 's')
		return (ft_printlen_type_s(info));
	else if (info->type == 'd' || info->type == 'i')
		info->prt_len = ft_intlen_base(info->id, "0123456789");
	else if (info->type == 'u')
		info->prt_len = ft_sizetlen_base((size_t)info->ux, "0123456789");
	else if (info->type == 'x')
		info->prt_len = ft_sizetlen_base((size_t)info->ux, "0123456789abcdef");
	else if (info->type == 'X')
		info->prt_len = ft_sizetlen_base((size_t)info->ux, "0123456789ABCDEF");
	else if (info->type == '%')
		info->prt_len = 1;
	else
		return (ft_error("Invalid format type"));
	if (info->prec < info->prt_len)
		return (info->prt_len);
	return (info->prec);
}
