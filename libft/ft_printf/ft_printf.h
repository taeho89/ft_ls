/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:54:11 by takwak            #+#    #+#             */
/*   Updated: 2024/10/19 06:38:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_printf
{
	char			flag;
	size_t			width;
	size_t			prec;
	int				prec_flag;
	char			type;
	size_t			prt_len;
	char			c;
	size_t			p;
	char			*s;
	int				id;
	unsigned int	ux;
}			t_printf;
int			ft_adrlen(size_t n);
int			ft_check_flag(const char *s, t_printf *info);
int			ft_check_width(const char *s, t_printf *info);
int			ft_check_prec(const char *s, t_printf *info);
int			ft_check_type(const char *s, va_list ap, t_printf *info);
size_t		ft_default_print(t_printf *info);
int			ft_error(const char *s);
t_printf	*ft_init_struct(t_printf *info);
size_t		ft_intlen_base(int n, const char *base);
size_t		ft_is_flag_minus(t_printf *info);
size_t		ft_is_flag_plus(t_printf *info);
size_t		ft_is_flag_sharp(t_printf *info);
size_t		ft_is_flag_space(t_printf *info);
size_t		ft_is_flag_zero(t_printf *info);
int			ft_is_valid_type(t_printf *info);
char		*ft_prec_set_zero(char *itoa_n, size_t symbol, t_printf *info);
int			ft_print_arg(t_printf *info, size_t *total_len);
size_t		ft_print_type(t_printf *info);
size_t		ft_print_type_c(char c);
size_t		ft_print_type_s(char *s, t_printf *info);
size_t		ft_print_type_id(int n, t_printf *info);
size_t		ft_print_type_u(unsigned int n, t_printf *info);
size_t		ft_print_type_x(unsigned int n, t_printf *info);
size_t		ft_print_type_largex(unsigned int n, t_printf *info);
size_t		ft_print_type_p(size_t adr);
int			ft_printf(const char *format_s, ...);
int			ft_printlen_arg(t_printf *info);
char		*ft_sizet_toa_base(size_t n, const char *base);
size_t		ft_sizetlen_base(size_t n, const char *base);
void		ft_type_c(va_list ap, t_printf *info);
void		ft_type_p(va_list ap, t_printf *info);
void		ft_type_s(va_list ap, t_printf *info);
void		ft_type_c(va_list ap, t_printf *info);
void		ft_type_i(va_list ap, t_printf *info);
void		ft_type_d(va_list ap, t_printf *info);
void		ft_type_u(va_list ap, t_printf *info);
void		ft_type_x(va_list ap, t_printf *info);
void		ft_type_largex(va_list ap, t_printf *info);
size_t		ft_write(const char *s, size_t size);
#endif
