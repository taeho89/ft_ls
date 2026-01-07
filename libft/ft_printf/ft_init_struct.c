/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:20:13 by takwak            #+#    #+#             */
/*   Updated: 2024/10/18 06:09:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_init_struct(t_printf *info)
{
	info = (t_printf *)malloc(sizeof(t_printf));
	info->flag = 0;
	info->width = 0;
	info->prec = 0;
	info->prec_flag = 0;
	info->type = 0;
	info->prt_len = 0;
	info->c = 0;
	info->p = 0;
	info->s = NULL;
	info->id = 0;
	info->ux = 0;
	return (info);
}
