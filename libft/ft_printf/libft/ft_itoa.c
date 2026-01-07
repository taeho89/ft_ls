/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:44:29 by takwak            #+#    #+#             */
/*   Updated: 2024/10/06 03:22:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_negative(int n, int size)
{
	char	*buf;

	size = size + 1;
	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return (NULL);
	buf[0] = '-';
	buf[size--] = '\0';
	while (size >= 1)
	{
		buf[size] = n % 10 * -1 + '0';
		n = n / 10;
		size--;
	}
	return (buf);
}

static char	*if_positive(int n, int size)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return (NULL);
	buf[size--] = '\0';
	while (size >= 0)
	{
		buf[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (buf);
}

char	*ft_itoa(int n)
{
	int		ori_n;
	char	*s;
	int		len;

	ori_n = n;
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	n = ori_n;
	if (n < 0)
		s = if_negative(n, len);
	else if (n > 0)
		s = if_positive(n, len);
	else
	{
		s = (char *)malloc(sizeof(char) * (2));
		if (s == NULL)
			return (NULL);
		s[1] = '\0';
		s[0] = '0';
	}
	return (s);
}
