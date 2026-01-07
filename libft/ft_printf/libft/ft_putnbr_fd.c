/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:46:33 by takwak            #+#    #+#             */
/*   Updated: 2024/10/22 16:28:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_fixed(char *tmp, int n, int len)
{
	if (n < 0)
	{
		len = len + 1;
		tmp[0] = '-';
		tmp[len--] = '\0';
		while (n != 0)
		{
			tmp[len--] = n % 10 * -1 + '0';
			n /= 10;
		}
	}
	else if (n > 0)
	{
		tmp[len--] = '\0';
		while (n != 0)
		{
			tmp[len--] = n % 10 + '0';
			n /= 10;
		}
	}
	else
	{
		tmp[1] = '\0';
		tmp[0] = '0';
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		ori_n;
	int		len;
	char	tmp[12];

	ori_n = n;
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	n = ori_n;
	ft_itoa_fixed(tmp, n, len);
	write(fd, tmp, ft_strlen(tmp));
}
// Have to free(tmp); but free() isn't External functs.
