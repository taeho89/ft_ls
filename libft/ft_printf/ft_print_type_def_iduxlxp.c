/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_def_iduxlxp.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:23:35 by takwak            #+#    #+#             */
/*   Updated: 2024/10/23 18:16:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_type_id(int n, t_printf *info)
{
	char		*tmp;
	char		*zero_set;
	size_t		tmp_len;
	size_t		print_len;

	if (info->prec_flag && info->prec == 0 && n == 0)
		return (0);
	print_len = 0;
	tmp = ft_itoa(n);
	tmp_len = ft_strlen(tmp);
	if (n < 0)
		tmp_len--;
	if (info->prec > tmp_len)
	{
		zero_set = ft_prec_set_zero(tmp, tmp_len, info);
		if (n < 0)
			print_len += ft_write("-", 1);
		print_len += ft_write(zero_set, ft_strlen(zero_set));
		free(zero_set);
		free(tmp);
		return (print_len);
	}
	print_len += ft_write(tmp, ft_strlen(tmp));
	free(tmp);
	return (print_len);
}

size_t	ft_print_type_u(unsigned int n, t_printf *info)
{
	char		*tmp;
	char		*zero_set;
	size_t		tmp_len;
	size_t		print_len;

	if (info->prec_flag && info->prec == 0 && n == 0)
		return (0);
	print_len = 0;
	tmp = ft_sizet_toa_base((size_t)n, "0123456789");
	tmp_len = ft_strlen(tmp);
	if (info->prec > tmp_len)
	{
		zero_set = (char *)ft_calloc(info->prec + 1, sizeof(char));
		ft_memset(zero_set, '0', info->prec - tmp_len);
		ft_strlcat(zero_set, tmp, info->prec + 1);
		print_len += ft_write(zero_set, info->prec);
		free(zero_set);
		free(tmp);
		return (print_len);
	}
	print_len += ft_write(tmp, tmp_len);
	free(tmp);
	return (print_len);
}

size_t	ft_print_type_x(unsigned int n, t_printf *info)
{
	char		*tmp;
	char		*zero_set;
	size_t		tmp_len;
	size_t		print_len;

	if (info->prec_flag && info->prec == 0 && n == 0)
		return (0);
	print_len = 0;
	tmp = ft_sizet_toa_base((size_t)n, "0123456789abcdef");
	tmp_len = ft_strlen(tmp);
	if (info->prec > tmp_len)
	{
		zero_set = (char *)ft_calloc(info->prec + 1, sizeof(char));
		ft_memset(zero_set, '0', info->prec - tmp_len);
		ft_strlcat(zero_set, tmp, info->prec + 1);
		print_len += ft_write(zero_set, info->prec);
		free(zero_set);
		free(tmp);
		return (print_len);
	}
	print_len += ft_write(tmp, tmp_len);
	free(tmp);
	return (print_len);
}

size_t	ft_print_type_largex(unsigned int n, t_printf *info)
{
	char		*tmp;
	char		*zero_set;
	size_t		tmp_len;
	size_t		print_len;

	if (info->prec_flag && info->prec == 0 && n == 0)
		return (0);
	print_len = 0;
	tmp = ft_sizet_toa_base((size_t)n, "0123456789ABCDEF");
	tmp_len = ft_strlen(tmp);
	if (info->prec > tmp_len)
	{
		zero_set = (char *)ft_calloc(info->prec + 1, sizeof(char));
		ft_memset(zero_set, '0', info->prec - tmp_len);
		ft_strlcat(zero_set, tmp, info->prec + 1);
		print_len += ft_write(zero_set, info->prec);
		free(zero_set);
		free(tmp);
		return (print_len);
	}
	print_len += ft_write(tmp, tmp_len);
	free(tmp);
	return (print_len);
}

size_t	ft_print_type_p(size_t adr)
{
	char		*tmp;
	size_t		print_len;

	print_len = 0;
	if (adr == 0)
		return (ft_write("(nil)", 5));
	tmp = ft_sizet_toa_base(adr, "0123456789abcdef");
	print_len += ft_write("0x", 2);
	print_len += ft_write(tmp, ft_strlen(tmp));
	free(tmp);
	return (print_len);
}
