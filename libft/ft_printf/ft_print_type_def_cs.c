/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_def_cs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:50:48 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 05:05:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_type_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (ft_error("Failed writing"));
	return (1);
}

size_t	ft_print_type_s(char *s, t_printf *info)
{
	size_t	s_len;

	if (s == NULL && (!info->prec_flag || info->prec >= 6))
		return (ft_write("(null)", 6));
	if (info->prec_flag && info->prec < ft_strlen(s))
		return (ft_write(s, info->prec));
	s_len = ft_strlen(s);
	return (ft_write(s, s_len));
}
